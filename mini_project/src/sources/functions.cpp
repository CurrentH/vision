#include "../headers/functions.hpp"

cv::MatND getHistogram(const cv::Mat &image)
{
    int numOfIm = 1;
    int channels[] = {0}; //The channels of the images used in the computation
    cv::Mat mask; //not using mask, so leave empty
    cv::MatND hist;
    int dimensions = 1;//dimensionality of the histogram
    int numOfBins[] = {256}; //number of bins
    float minMaxValue[] = {0.0, 255.0}; //the min and max value of the bins
    const float* ranges[] = {minMaxValue}; //Array of min-max value arrays, so every dimension is assigned min and max
    cv::calcHist(&image, numOfIm, channels, mask, hist, dimensions, numOfBins, ranges);
    return hist; //the returned type is 32FC1
}

Mat getHistogramImage(const cv::Mat &image)
{
    int numOfBins = 256;
    MatND hist= getHistogram(image);

    // Get min and max bin values
	double maxVal=0, minVal=0;
	cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);
    Mat histImg = cv::Mat::zeros(numOfBins,numOfBins, CV_8UC1);

    int hpt = static_cast<int>(0.9*numOfBins); // set highest point at 90% of numOfBins

    for( int h = 0; h < numOfBins; h++ ) // Draw a vertical line for each bin
	{
		float binVal = hist.at<float>(h);
		int intensity;
		if (binVal != 0){
            intensity = static_cast<int>(hpt* binVal/maxVal) ;
            cv::line(histImg,cv::Point(h,numOfBins), cv::Point(h,numOfBins-intensity), cv::Scalar::all(255));
        }
    }
	return histImg;
}

void hist(Mat image, std::string name, int posX, int posY, int width, int height)
{
	namedWindow(name.c_str(), CV_WINDOW_NORMAL);
	resizeWindow(name.c_str(), width, height);
	moveWindow(name.c_str(), posX, posY);
	imshow(name, getHistogramImage(image));
}

void hist(std::vector<Mat> &image, std::string name, int posX, int posY, int width, int height)
{
        for (int i = 0; i < image.size(); i++){
                std::stringstream ss;
                ss << i;
                hist(image[i], name + ss.str(), posX, posY + i * height);
        }
}

void show(Mat image, std::string name, int posX, int posY, int width, int height)
{
	namedWindow(name.c_str(), CV_WINDOW_NORMAL);
	resizeWindow(name.c_str(), width, height);
	moveWindow(name.c_str(), posX, posY);
	imshow(name, image);
}

void show(std::vector<Mat> &image, std::string name, int posX, int posY, int width, int height)
{
        for (int i = 0; i < image.size(); i++){
                std::stringstream ss;
                ss << i;
                show(image[i], name + ss.str(), posX, posY + i * height);
        }
}

void adaptiveMedian(Mat &image, Mat &dst, int maxMaskSize)
{
	if (image.cols != dst.cols || image.rows != dst.rows) dst = image;
        Mat imgCopy = image.clone();
	copyMakeBorder(imgCopy, imgCopy, maxMaskSize, maxMaskSize, maxMaskSize, maxMaskSize, BORDER_CONSTANT, 0);

	for (int y = maxMaskSize; y < imgCopy.rows - maxMaskSize; y++){
		for (int x = maxMaskSize; x < imgCopy.cols - maxMaskSize; x++){
			for (int i = 1; i <= maxMaskSize; i++){
				std::vector<uint8_t> list;
				for (int s = -i; s <= i; s++){
					for (int t = -i; t <= i; t++){
						list.push_back(imgCopy.at<uint8_t>(y + s, x + t));
					}
				}
				sort(list.begin(), list.end());

				uint32_t lowPtr = 0;
				uint32_t highPtr = list.size() - 1;

				while (list[lowPtr] == 0 && lowPtr < list.size()) lowPtr++;

				if (list[lowPtr] == 255 || lowPtr == list.size()) continue;
				while (list[highPtr] == 255 && highPtr > 0) highPtr--;

				if (lowPtr >= highPtr) continue;

				dst.at<uint8_t>(y - maxMaskSize, x - maxMaskSize) = list[(lowPtr + highPtr) / 2];
				break;
			}
		}
	}

}

cv::Mat computeDFT(cv::Mat &image)
{
	Mat padded;

	// Get the optimal size for dft output
	int m = getOptimalDFTSize(image.rows);
	int n = getOptimalDFTSize(image.rows);

	copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = {Mat_<float> (padded), Mat::zeros(padded.size(), CV_32F)};

	Mat complex;

	merge(planes, 2, complex);

	dft(complex, complex, DFT_COMPLEX_OUTPUT);

	return complex;
}

void rearrangeComplex(Mat &image)
{

    // crop if it has an odd number of rows or columns
    image = image(Rect(0, 0, image.cols & -2, image.rows & -2));

	// Get half the width and height of the complex image
    int cx = image.cols / 2;
    int cy = image.rows / 2;

	// Dividing complex image into four parts
    Mat q0(image, Rect(0, 0, cx, cy));
    Mat q1(image, Rect(cx, 0, cx, cy));
    Mat q2(image, Rect(0, cy, cx, cy));
    Mat q3(image, Rect(cx, cy, cx, cy));

	// Rearrange the four pats of the image to have dc in origo
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);
}

void showComplex(Mat complex, std::string name, int posX, int posY, int width, int height)
{
	Mat magI;
    Mat planes[] = {
        Mat::zeros(complex.size(), CV_32F),
        Mat::zeros(complex.size(), CV_32F)
    };

    split(complex, planes);

    magnitude(planes[0], planes[1], magI);

    magI += Scalar::all(1);

    log(magI, magI);
    rearrangeComplex(magI);

    normalize(magI, magI, 1, 0, NORM_INF);
    show(magI, name, posX, posY, width, height);
}

void showResult(Mat complex, std::string name, int posX, int posY, int width, int height)
{
    Mat result;

	idft(complex, result);

	Mat planes[] = {
        Mat::zeros(complex.size(), CV_32F),
        Mat::zeros(complex.size(), CV_32F)
    };

    split(result, planes);

    magnitude(planes[0], planes[1], result);
    normalize(result, result, 0, 1, NORM_MINMAX);
    show(result, name, posX, posY, width, height);
}

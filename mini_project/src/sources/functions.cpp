#include "../headers/functions.hpp"

cv::MatND getHistogram(const cv::Mat &image){
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

Mat getHistogramImage(const cv::Mat &image){
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

void hist(Mat image, std::string name, int posX, int posY, int width, int height){
	namedWindow(name.c_str(), CV_WINDOW_NORMAL);
	resizeWindow(name.c_str(), width, height);
	moveWindow(name.c_str(), posX, posY);
	imshow(name, getHistogramImage(image));
}

void hist(std::vector<Mat> &image, std::string name, int posX, int posY, int width, int height){
        for (int i = 0; i < image.size(); i++){
                std::stringstream ss;
                ss << i;
                hist(image[i], name + ss.str(), posX, posY + i * height);
        }
}

void show(Mat image, std::string name, int posX, int posY, int width, int height){
	namedWindow(name.c_str(), CV_WINDOW_NORMAL);
	resizeWindow(name.c_str(), width, height);
	moveWindow(name.c_str(), posX, posY);
	imshow(name, image);
}

void show(std::vector<Mat> &image, std::string name, int posX, int posY, int width, int height){
        for (int i = 0; i < image.size(); i++){
                std::stringstream ss;
                ss << i;
                show(image[i], name + ss.str(), posX, posY + i * height);
        }
}

void adaptiveMedian(Mat &image, Mat &dst, int maxMaskSize){
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

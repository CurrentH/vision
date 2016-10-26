#ifndef IMAGE2
#define IMAGE2

#include "../headers/image2.hpp"
#include "../headers/functions.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <stdlib.h>

using namespace cv;

string type2str(cv::Mat &image){
	int type = image.type();
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

int process4_1(){
/**
	Mat image = imread("../images/Image4_2.png", CV_LOAD_IMAGE_GRAYSCALE);

	Mat padded;
	int m = getOptimalDFTSize(image.rows);
	int n = getOptimalDFTSize(image.cols);
	copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
	Mat complexI;
	merge(planes, 2, complexI);

	dft(complexI, complexI);

	split(complexI, planes);
	magnitude(planes[0], planes[1], planes[0]);
	Mat magI = planes[0];

	magI += Scalar::all(1);
	log(magI, magI);

	magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

	int cx = magI.cols/2;
	int cy = magI.rows/2;

	Mat q0(magI, Rect(0, 0, cx, cy));
	Mat q1(magI, Rect(cx, 0, cx, cy));
	Mat q2(magI, Rect(0, cy, cx, cy));
	Mat q3(magI, Rect(cx, cy, cx, cy));

	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	normalize(magI, magI, 0, 1, CV_MINMAX);


	imshow("Input Image", image);

	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			magI.at<uint8_t>(i + 850, j + 1900) = 0;
			magI.at<uint8_t>(-i + magI.rows - 850, j + 1900) = 0;
			magI.at<uint8_t>(i + 850, -j - 1900) = 0;
			magI.at<uint8_t>(-i + magI.rows - 850, -j - 1900) = 0;
		}
	}

	show(magI, "Original - 1", 0);

	cv::Mat inverseTransform;
	cv::dft(magI, inverseTransform, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);

	imshow("Test", inverseTransform);

	*/

	cv::Mat image = cv::imread("../images/Image4_1.png", CV_LOAD_IMAGE_GRAYSCALE);

	cv::Mat fImage;
	image.convertTo(fImage, CV_32F);

	cv::Mat fourierTransform;
	cv::dft(fImage, fourierTransform, cv::DFT_SCALE | cv::DFT_COMPLEX_OUTPUT);

	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			fourierTransform.at<uint8_t>(i, j) = 0;
			//fourierTransform.at<uint8_t>(-i + fourierTransform.rows - 850, j + 1900) = 0;
			//fourierTransform.at<uint8_t>(i, -j) = 0;
			//fourierTransform.at<uint8_t>(-i + fourierTransform.rows - 850, -j - 1900) = 0;
		}
	}

	cv::Mat fourierTransformCopy(fourierTransform);
	normalize(fourierTransformCopy, fourierTransformCopy, 0, 1, CV_MINMAX);
	std::cout << type2str(fourierTransformCopy) << std::endl;
	//show(fourierTransformCopy, "Fourier");

	cv::Mat inverseTransform;
	cv::dft(fourierTransform, inverseTransform, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);

	cv::Mat result;
	inverseTransform.convertTo(result, CV_8U);

	show(result, "Result");

/*

	std::vector<Mat> results;

	results.push_back(Mat());
	dft(image, image, 0, image.rows);
*/
	/*
	show(image, "Original - 3", 1000);
	hist(image, "Original Hist - 3", 1200);
	show(results, "Processed - 3 ", 1000, 250);
	hist(results, "Processed Hist - 3 ", 1200, 250);
	*/

	std::cout << "Done image 3!" << std::endl;
}

#endif

// Inspiration from: http://docs.opencv.org/2.4/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html

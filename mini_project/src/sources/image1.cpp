#ifndef IMAGE1
#define IMAGE1

#include "../headers/image1.hpp"
#include "../headers/functions.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>
#include <string>

using namespace cv;

int process1(){
	Mat image;
	image = cv::imread("../images/Image1.png", CV_LOAD_IMAGE_GRAYSCALE);

	std::vector<Mat> results;

	results.push_back(Mat());
	adaptiveMedian(image, results[0], 20);

	results.push_back(Mat());
	equalizeHist(results[0], results[1]);

	results.push_back(Mat());
	GaussianBlur(results[0], results[2], Size(3, 3), 2, 5);

	show(image, "Original - 1", 0);
	hist(image, "Original Hist - 1", 200);
	show(results, "Processed - 1 ", 0, 250);
	hist(results, "Processed Hist - 1 ", 200, 250);

	std::cout << "Done image 1!" << std::endl;

	return 0;
}

#endif

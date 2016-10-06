#ifndef IMAGE2
#define IMAGE2

#include "../headers/image2.hpp"
#include "../headers/functions.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>
#include <string>
#include <stdlib.h>

using namespace cv;

int process2(){
	Mat image;
	image = cv::imread("../images/Image2.png", CV_LOAD_IMAGE_GRAYSCALE);

	std::vector<Mat> results;

	results.push_back(Mat());
	adaptiveMedian(image, results[0], 20);

	results.push_back(Mat());
	equalizeHist(results[0], results[1]);

	results.push_back(Mat());
	GaussianBlur(results[1], results[2], Size(3, 3), 2, 5);

	show(image, "Original - 2", 500);
	hist(image, "Original Hist - 2", 700);
	show(results, "Processed - 2 ", 500, 250);
	hist(results, "Processed Hist - 2 ", 700, 250);

	std::cout << "Done image 2!" << std::endl;

	return 0;
}

#endif

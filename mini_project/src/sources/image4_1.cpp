#ifndef IMAGE2
#define IMAGE2

#include "../headers/image4_1.hpp"
#include "../headers/functions.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>
#include <string>
#include <stdlib.h>

using namespace cv;

int process4_1(){
	Mat image;
	image = cv::imread("../images/Image4_1.png", CV_LOAD_IMAGE_GRAYSCALE);

	show(image, "Original - 4_1", 1500);

	Mat complex = computeDFT(image);

	showComplex(complex, "Complex - 4_1", 1700);

	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			complex.at<float>(i + 250, j + 3825) = 0;
			complex.at<float>(complex.rows - (i + 250), complex.cols * 2 - (j + 3825)) = 0;
			complex.at<float>(i + 75, j + 250) = 0;
			complex.at<float>(complex.rows - (i + 75), complex.cols * 2 - (j + 250)) = 0;
		}
	}

	showComplex(complex, "Result complex - 4_1", 1700, 250);

	showResult(complex, "Result - 4_1", 1500, 250);

	std::cout << "Done image 4_1!" << std::endl;

	return 0;
}

#endif

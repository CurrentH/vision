#ifndef IMAGE2
#define IMAGE2

#include "../headers/image4_2.hpp"
#include "../headers/functions.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>
#include <string>
#include <stdlib.h>

using namespace cv;

int process4_2(){
	Mat image;
	image = cv::imread("../images/Image4_2.png", CV_LOAD_IMAGE_GRAYSCALE);

	show(image, "Original - 4_2", 1000);
	hist(image, "Original Hist - 4_2", 1200);

	Mat complex = computeDFT(image);

	std::cout << complex.channels() << std::endl;

	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			
		}
	}

	showComplex(complex, "Complex - 4_2");

	showResult(complex, "Result - 4_2");

	return 0;
}

#endif

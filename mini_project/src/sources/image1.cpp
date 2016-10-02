#ifndef IMAGE1
#define IMAGE1

#include "../headers/image1.hpp"

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int process1(){
	Mat image;
	Mat dst;
	image = cv::imread("../images/Image1.png", CV_LOAD_IMAGE_GRAYSCALE);

	medianBlur ( image, dst, 11 );

	if ( !image.data )
	{
		printf("No image data \n");
		return -1;
	}

	namedWindow("Display Image", CV_WINDOW_NORMAL );
	imshow("Display Image", dst);

	waitKey(0);

	return 0;
}

#endif

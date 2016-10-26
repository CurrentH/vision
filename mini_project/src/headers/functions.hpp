#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>
#include <string>

using namespace cv;

cv::MatND getHistogram(const cv::Mat &image);

Mat getHistogramImage(const cv::Mat &image);

void hist(Mat image, std::string name, int posX = 0, int posY = 0, int width = 250, int height = 200);
void hist(std::vector<Mat> &image, std::string name, int posX = 0, int posY = 0, int width = 250, int height = 200);

void show(Mat image, std::string name, int posX = 0, int posY = 0, int width = 250, int height = 200);
void show(std::vector<Mat> &image, std::string name, int posX = 0, int posY = 0, int width = 250, int height = 200);

void adaptiveMedian(Mat &image, Mat &dst, int maxMaskSize);

#endif

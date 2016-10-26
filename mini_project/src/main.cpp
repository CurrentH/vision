#include "headers/image1.hpp"
#include "headers/image2.hpp"
#include "headers/image3.hpp"
#include "headers/image4_1.hpp"
#include "headers/image4_2.hpp"

#include <opencv2/opencv.hpp>

#include <unistd.h>

int main(){

	//process1();
	//process2();
	//process3();
	process4_1();
	process4_2();

	usleep(1000000);

	cv::waitKey();

	return 0;
}

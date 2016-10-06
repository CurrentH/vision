#include "headers/image1.hpp"
#include "headers/image2.hpp"
#include "headers/image3.hpp"
#include "headers/image4_1.hpp"
#include "headers/image4_2.hpp"

#include <opencv2/opencv.hpp>

int main(){

	process1();
	process2();
	process3();
	process4_1();
	process4_2();

	cv::waitKey();

	return 0;
}

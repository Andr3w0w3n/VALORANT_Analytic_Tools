#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;


int main() {

	string path = "C:\\Users\\epica\\Videos\\2022-06-18 22-14-47.mp4"; //Blank Map

	VideoCapture cap(path);
	Mat img;
	Mat imgCont, imgBright;


	Mat cropped_image = img(Range(80, 460), Range(60, 420));

	imgBright = cropped_image - Scalar(125, 125, 125); //changing brightness, lowering
	imgBright.convertTo(imgCont, -1, 1.75, 0); //chaning contrast, raising

	Mat matte;
	Scalar upBound = Scalar(110, 110, 110);
	Scalar lowBound = Scalar(60, 60, 60);
	inRange(imgCont, lowBound, upBound, matte);

	imshow("Imaged Matted", matte);
	imshow("Origional Image (Cropped)", cropped_image);

	return 0;

}
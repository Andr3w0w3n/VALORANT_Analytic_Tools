#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;


int main() {

	string path = "C:\\Users\\epica\\Videos\\LagClip.mp4";

	VideoCapture cap(path);
	Mat img;

	while (true) {

		cap.read(img);

		imshow("Image", img);
		waitKey(1);
	}

}
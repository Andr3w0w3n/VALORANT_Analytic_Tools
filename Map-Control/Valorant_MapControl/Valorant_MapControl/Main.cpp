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
	Mat imgGray, imgCanny;

	while (true) {

		cap.read(img);

		//Canny(img, imgCanny, 50, 150);
		
		//cropped image is (y_Range, x_Range)
		Mat cropped_image = img(Range(70, 430), Range(150, 330));
		cvtColor(cropped_image, imgGray, COLOR_BGR2GRAY);
		Mat rgbchannel[3];

		//imshow("Image", img);
		//imshow("Image Canny", imgCanny);
		imshow("Image Gray", imgGray);
		waitKey(1);
	}
	destroyAllWindows();
	return 0;
}
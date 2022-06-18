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
	Mat imgCont, imgBright;

	while (true) {

		cap.read(img);

		//Canny(img, imgCanny, 50, 150);
		
		//cropped image is (y_Range, x_Range)
		Mat cropped_image = img(Range(70, 430), Range(80, 430));
		
		
		//messing with the colors a bit
		//cvtColor(cropped_image, imgGray, COLOR_BGR2GRAY);
		
		//attempted splitting the image into RGB to modify but found I could just adjust the brightness and contrast and get a similar result
		//Mat rgbchannel[3];

		cropped_image.convertTo(imgCont, 1, -2, 0);//changing contrast
		imgBright = imgCont - Scalar(80, 80, 80);//changing brightness


		//imshow("Image", img);
		//imshow("Image Canny", imgCanny);
		imshow("Image Contrasted", imgCont);
		imshow("Image Brighted & Constrasted", imgBright);
		waitKey(1);
	}
	destroyAllWindows();
	return 0;
}
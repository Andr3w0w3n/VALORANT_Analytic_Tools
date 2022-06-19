#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

Mat findingFogPixels(Mat image) {
	//this returns a matte of just the fog of war pixels

	//screengrabbed values (over discord and screengrabbed)
	//General: Red: 94, Green: 91, Blue: 93
	//Site: Red: 110, Green: 114, Blue: 68

	//non-site FOW
	Mat matte;
	Scalar upBound = Scalar(110,110,110);
	Scalar lowBound = Scalar(60, 60, 60);
	inRange(image, lowBound, upBound, matte);
	return matte;

	///////////////TO-DO///////////////
	//Need to add a site recognition FOW and need to add a blank map to do a "Subraction" of unwanted pixels

}

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
		
		//lowering the brightness and then raising the contrast 
		imgBright = cropped_image - Scalar(125, 125, 125); //changing brightness, lowering
		imgBright.convertTo(imgCont, -1, 1.75, 0); //chaning contrast, raising


		Mat mattedImage = findingFogPixels(imgCont);


		//finding pixel positions
		// input, binary image
		Mat locations;   // output, locations of non-zero pixels
		findNonZero(mattedImage, locations);
		// access pixel coordinates
		Point pnt = locations.at<Point>(0);
		cout << pnt << endl;

		imshow("Image Contrasted & Brighted", imgCont);
		//imshow("Image Brighted", imgBright);
		imshow("Imaged Matted", mattedImage);
		imshow("Origional Image (Cropped)", cropped_image);
		waitKey(1);
	}
	return 0;

}
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


//have to add these in order to make sure that 
using namespace cv;
using namespace std;


//importing images
void main() {

	string path = "/*FILE PATH*/";
	Mat img = imread(path);
	imshow("Image", img);
	//you have to write this to prevent it closing. If a value is in the parameter,
	// it gives a certain time until close (millisecond)
	waitKey(0);

}

//importing video
void main() {
	
	string path = "/*FILE PATH*/";
	VideoCapture cap(path);
	Mat img;
	
	while(true){
		
		cap.read(img);
		
		imshow("Image", img);
		waitKey(1);
	}

}

// changing images w/basic functions
void main() {
	
	string path = "/*FILE PATH*/";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; 
	
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7,7), 5, 0);
	//edge detector, Canny is the edge detector
	Canny(imgBlur, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);
	
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	
	waitKey(0);
}

//resize and crop images

void main() {
	
	string path = "/*FILE PATH*/";
	Mat img = imread(path);
	Mat imgResize;
	
	//outputs the image size into the console
	cout << img.size() << endl;
	//actual resize function
	resize(img, imgResize, Size(640, 480));
	//this also works for scaling it down using a percentage
	resize(img, imgResize, Size(), 0.5, 0.5);
	
	
	imshow("Image", img);
	
	waitKey(0);
}
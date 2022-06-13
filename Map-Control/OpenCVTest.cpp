#include "opencv2/opencv.hpp"


public static void main(String args[]){
	VideoCapture cap(videoFile);
	
	if(!cap.isOpened()){
		cout << "Error opening video stream or file" << endl;
		return -1;
	}
	
	Mat frame;
	// Capture frame-by-frame
	cap >> frame;
	
	//If the frame is empty, break
	if(frame.empty())
		break;
}

#include <opencv2/opencv/hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

	Mat img = imread("test.jpg")
	cout << "Width: " << img.size().width << endl;
	cout << "Height: " << img.size().height << endl;
	cout << "Channels: " << img.channels() << endl;
	//cropping image
	Mat cropped_image = img(Range(80,280)), Range(150,330));
	
	//displaying image
	imshow("Origional Image", img);
	imshow("Cropped Image", cropped_image);
	
	imwrite("Cropped Image.jpg, cropped_image);
	
	//0 means loop infinitely
	waitKey(0)
	destroyAllWindows();
	return 0;
}
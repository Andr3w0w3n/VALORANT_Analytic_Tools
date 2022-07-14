#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "Tile.h"

using namespace std;
using namespace cv;

Mat findingFogPixels(Mat image) {
	//this returns a matte of just the fog of war pixels

	//screengrabbed values (over discord and screengrabbed)
	//General: Red: 94, Green: 91, Blue: 93
	//Site: Red: 110, Green: 114, Blue: 68

	//non-site FOW
	Mat matte;
	Scalar upBound = Scalar(255,255,255);
	Scalar lowBound = Scalar(40, 40, 40);
	inRange(image, lowBound, upBound, matte);
	return matte;

	///////////////TO-DO///////////////
	//Need to add a site recognition FOW and need to add a blank map to do a "Subraction" of unwanted pixels

}

// Image Main, will re-open once the origional array is figured out, as to take the development in steps
//
/*int main() {

	//string path = "C:\\Users\\epica\\Videos\\2022-06-18 22-15-47.mp4"; //Test run through ascent
	string path = "C:\\Users\\epica\\Videos\\2022-06-18 22-14-47.mp4"; //Blank Map

	VideoCapture cap(path);
	Mat img;
	Mat imgCont, imgBright;

	while (true) {

		cap.read(img);

		//Canny(img, imgCanny, 50, 150);
		
		//cropped image is (y_Range, x_Range)
		Mat cropped_image = img(Range(80, 460), Range(60, 420));
		
		//attempted splitting the image into RGB to modify but found I could just adjust the brightness and contrast and get a similar result
		//Mat rgbchannel[3];
		
		//lowering the brightness and then raising the contrast 
		imgBright = cropped_image - Scalar(125, 125, 125); //changing brightness, lowering
		imgBright.convertTo(imgCont, -1, 1.75, 0); //chaning contrast, raising


		Mat mattedImage = findingFogPixels(imgCont);


		//finding pixel positions
		// input, binary image
		Mat locations;   // output, locations of non-zero pixels
		//findNonZero(mattedImage, locations);
		// access pixel coordinates
		//Point pnt = locations.at<Point>(0);
		//cout << pnt << endl;

		Mat imgCanny;
		Canny(imgCont, imgCanny, 50, 200);

		imshow("Image Contrasted & Brighted", imgCont);
		//imshow("Image Brighted", imgBright);
		imshow("Imaged Matted", mattedImage);
		imshow("Origional Image (Cropped)", cropped_image);
		imshow("Edge Detection", imgCanny);


		
		waitKey(1);
	}
	return 0;

}*/

int main() {

	const int size = 5;
	const int tileNum = size * size;
	int x = 0;
	int y = 0;
	Tile tiles[tileNum];

	list<int> adj[tileNum];

	//this creates the entire grid of tiles and puts them in a linear array
	//currently this is very rough and includes tiles that will not be used
	for (int i = 0; i < tileNum; i++) {
		tiles[i] = Tile(x, y, true);
		if (x < size) {
			x++;
		}else{
			y++;
			x = 0;
		}
	}

	
	return 0;
}
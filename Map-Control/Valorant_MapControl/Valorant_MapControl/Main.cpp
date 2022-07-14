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

void updateConTiles(list<int> adj[], Tile tiles[]) {
	//this is where all the tiles will be updated
	for (int i = 0; i < sizeof(adj); i++) {
		bool found = false;
		bool end = false;
		bool pause = false;
		//check to see if 
		if (tiles[i].getControl() == 100.0) {
			list<int>::iterator object = adj[i].begin();
			do {
				if (object == adj[i].end()) {
					end = true;
				}if (tiles[object].getControl() < 100.0) {
					found = true;
				}
				else if (!end) {
					object++;
				}
			} while (!found && !end);

				//if tile is in the middle of lowering control, look to see if it needs to pause
				// due to no longer being surrounded by non-controlled tiles. This is in hopes
				// of keeping a "realistic probability" with the tiles if you look away and look back
		}
		else if (tiles[i].getControl() < 100.0 && tiles[i].getControl() > 0.0) {
			list<int>::iterator object = adj[i].begin();
			do {
				if (object == adj[i].end()) {
					end = true;
				}else if(tiles[object].getControl() < tiles[i].getControl()) {
					found = true;
				}else if (!end) {
					object++;
				}
			} while (!found && !end);
			if (!found) {
				pause = true;
			}		
		}
		if (pause && !found) {
			tiles[i].pauseLosingControl();
		}
		else if (found) {
			tiles[i].beginLosingControl();
		}
	}
}

//I forgot what I wanted this to do, maybe check to see if x,y is valid?
// This will have to be repeated for any of the adjacency checks
bool checkXY(int x, int y) {



}

int insertSurroundingNum(int x, int y, int size, int itt) {

	//itt will be the value of whatever is passed through, as to itterate over the 9
	// potentially surrounding objects. This should help setup a default adjacency list
	// without the out of map points.
	switch (itt) {
		//top left
		case 1:
			if ((x - 1 != -1) && (y - 1 != -1)) {
				return size * (y - 1) + (x - 1);
			}

			//top mid
		case 2:
			if (y - 1 != -1) {
				return size * (y - 1) + (x);
			}

			//top right
		case 3:
			if ((x + 1 != size) && (y - 1 != -1)) {
				return size * (y - 1) + (x + 1);
			}

			//left
		case 4:
			if ((x - 1 != -1)) {
				return size * (y)+(x - 1);
			}

			//right
		case 5:
			if ((x + 1 != size)) {
				return size * (y)+(x + 1);
			}

			//bottom left
		case 6:
			if ((x - 1 != -1) && (y + 1 != size)) {
				return size * (y + 1) + (x - 1);
			}

			//bottom mid
		case 7:
			if (y + 1 != size) {
				return size * (y + 1) + (x);
			}

			//bottom right
		case 8:
			if ((x + 1 != size) && (y + 1 != size)) {
				return size * (y + 1) + (x + 1);
			}
	
		return -1;
	}
}

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
		checkXY(x, y);
		tiles[i] = Tile(x, y, true);
		for (int j = 1; j <= 8; j++) {
			int val = insertSurroundingNum(x, y, size, j);
			if (val != -1) {
				adj[i].push_front(val);
			}	
		}

		if (x < size) {
			x++;
		}
		else {
			y++;
			x = 0;
		}
	}


	return 0;
}
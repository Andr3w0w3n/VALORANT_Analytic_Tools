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

//some more variables
//could save some space and potentially adding 
string path;

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

Mat drawSquares(int canvasSize, int tileCount, int thickness, Tile tiles[]) {

	//cout << "Drawing Squares\n";

	//variables
	double greyValue = 150.0;
	Mat image(canvasSize, canvasSize, CV_8UC3, Scalar(255, 255, 255)); //blank white canvas 1000x1000
	int tileSize = canvasSize / tileCount;

	int y1 = 0;
	int y2 = tileSize;

	// Creating a blank image with
	// white background
	

	//making a grid of squares 
	for (int i = 0; i < tileCount; i++) {
		
		int x1 = 0;
		int x2 = tileSize;

		for (int j = 0; j < tileCount; j++) {

			int gAndB = int(((100.0 - tiles[(i*tileCount+j)].getControl()) / 100.0) * greyValue);
			int red = int(((100.0 - tiles[(i*tileCount+j)].getControl()) / 100.0) * (255.0 - greyValue));

			rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(greyValue - gAndB, greyValue - gAndB, greyValue + red), FILLED);
			//cout << "created square with color (B: " << greyValue - gAndB << ", G: " << greyValue - gAndB << ", R: " << greyValue + red << ")\n";
			//cout << "tile control: " << tiles[i].getControl() << endl;
			rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(15, 15, 15), thickness, LINE_4);

			x1 += tileSize;
			x2 += tileSize;
		}
		y1 += tileSize;
		y2 += tileSize;
	}

	return image;
}

//this may not actually change anything???
Tile updateConTiles(list<int> adj[], Tile tiles[], Tile tile, int oneDTileCount) {
	//this is where all the tiles will be updated

	//cout << "updating tiles\n";
	bool found = false;
	bool end = false;
	bool pause = false;
	//check to see if there are any tiles that will update the og tile
		
	if (tile.getControl() == 100.0) {

		for (list<int>::iterator j = adj[(tile.y * oneDTileCount + tile.x)].begin(); j != adj[(tile.y * oneDTileCount + tile.x)].end(); ++j) {
			tiles[*j].printTile();
			if (tiles[*j].getControl() < 100.0) {
				found = true;
			}
		}

			//if tile is in the middle of lowering control, look to see if it needs to pause
			// due to no longer being surrounded by non-controlled tiles. This is in hopes
			// of keeping a "realistic probability" with the tiles if you look away and look back
	}
	else if (tile.getControl() < 100.0 && tile.getControl() > 0.0) {
		
		for (list<int>::iterator j = adj[(tile.y * oneDTileCount + tile.x)].begin(); j != adj[(tile.y * oneDTileCount + tile.x)].end(); ++j) {
			tiles[*j].printTile();
			if (tiles[*j].getControl() < 100.0) {
				found = true;
			}
		}
		if (!found) {
			pause = true;
		}		
	}
	if (pause && !found) {
		tile.pauseLosingControl();
	}
	else if (found) {
		tile.beginLosingControl();
	}

	tile.updateCon();

	return tile;
}


////////TO-DO/////////
//I forgot what I wanted this to do, maybe check to see if x,y is valid?
bool checkXY(int x, int y) {

	//stand-in
	return true;

}

int insertSurroundingNum(int x, int y, int size, int itt) {

	//itt will be the value of whatever is passed through, as to itterate over the 9
	// potentially surrounding objects. This should help setup a default adjacency list
	// without the out of map points.

	//Corners are currently excluded to be delt with later
	switch (itt) {
			
			//top left
		case 1:
			return -1;

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
			return -1;

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
			return -1;

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
			return -1;

			if ((x + 1 != size) && (y + 1 != size)) {
				return size * (y + 1) + (x + 1);
			}
	}
	return -1;
}

int main() {

	//Variables for tile creation
	const int size = 5;
	const int tileNum = size * size;
	int x = 0;
	int y = 0;
	bool controlled = true;
	Tile tiles[tileNum];
	list<int> adj[tileNum];

	//variables for drawing tiles
	const int tileEdgeThickness = 3;
	const int canvasSize = 1000;

	//variables for reading the video
	//string path = "C:\\Users\\epica\\Videos\\2022-06-18 22-15-47.mp4"; //Test run through ascent
	//path = "C:\\Users\\epica\\Videos\\2022-06-18 22-14-47.mp4"; //Blank Map
	//VideoCapture cap(path);
	Mat img;
	//Mat imgCont, imgBright;

	

	//this creates the entire grid of tiles and puts them in a linear array
	//currently this is very rough and includes tiles that will not be used
	for (int i = 0; i < tileNum; i++) {
		
		//this if statement is just to create some non-controlled squares
		if (i >= size*(size-1)) {
			controlled = false;
		}
		//checkXY(x, y);
		//cout << "X: " << x << ", Y: " << y << ", Control: " << controlled << endl;
		tiles[i] = Tile(x, y, controlled);
		
		
		for (int j = 1; j <= 8; j++) {
			int val = insertSurroundingNum(x, y, size, j);
			if (val != -1) {
				adj[i].push_front(val);
			}	
		}
		//cout << tiles[i].getControl() << endl;
		if (x < size-1){
			x++;
		}
		else {
			y++;
			x = 0;
		}
		//cout << "\nBuilt Tile: " << i+1;
	}



	/////////////TO-DO////////////////
	//Testing statements
	/*
	//WHAT ARE THESE EXTRA TILES????? 
	// HOW WERE THESE CREATED????
	// Will probably need to figure out how to not creat these
	//  or figure out a way to delete them.
	// infinite??? It broke the write method
	int total = 1;
	for (int i = 0; i < sizeof(tiles)/sizeof(tiles[0]); i++) {
		tiles[i].printTile();
		cout << "" << total << "\n\n";
		total++;
	}
	
	//this worked fine
	/*for (int i = 0; i < tileNum; i++) {
		tiles[i].printTile();
		cout << "" << total << "\n\n";
		total++;
	}*/
	///////////////////////////////////

	
	
	//reading the video portion
	/*while (true) {
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
	*/

	// https://stackoverflow.com/questions/60204868/how-to-write-mp4-video-with-opencv-c
	//creating the write video
	string filename = "Test_003";
	VideoWriter writer;
	int codec = VideoWriter::fourcc('a', 'v', 'c', '1');
	double fps = 30.0;
	Size sizeFrame(1000, 1000);
	string filepath = "E:\\Users\\epica\\Videos\\ValorantMapControl Tool\\" + filename +".mp4";
	bool isColor = true;
	writer.open(filepath, codec, fps, sizeFrame, isColor);
	cout << "Started writing video... " << endl;
	//To be plugged into the reading the video potion to be able to do each frame
	Mat squares;

	for (int i = 0; i < 240; i++) {
		squares = drawSquares(canvasSize, size, tileEdgeThickness, tiles);
		imshow("Edge Detection", squares);
		//waitKey(0);
		writer.write(squares);

		//Will need to update each tile separately, this will have to be optimized
		for (int i = 0; i < tileNum; i++) {
			tiles[i] = updateConTiles(adj, tiles, tiles[i], size);
		}
	}
	writer.release();
	cout << "Write complete !" << endl;

	return 0;
}
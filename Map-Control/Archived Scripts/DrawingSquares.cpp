#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main(){

	//https://stackoverflow.com/questions/40120433/draw-rectangle-in-opencv
	
	int x = 0;
	int y = 0;
	int width = 10;
	int height = 10;
	
	//the rectangle
	cv::Rect rect(x, y, width, height);
	
	//top left corner
	cv::Point pt1(x, y);
	
	//bottom right corner
	cv::Point pt2(x + width, y + height);
	
	// These two calls...
	cv::rectangle(img, pt1, pt2, cv::Scalar(0, 255, 0));
	// essentially do the same thing
	cv::rectangle(img, rect, cv::Scalar(0, 255, 0))

	return 0;
}

//reminder: openCV uses BGR instead of RGB for number coloring

//cv.rectangle(img, topLeftPoint, bottomRightPoint, COLOR, THICKNESS)
//cv.filled for the [THICKNESS] portion will fill the rectangle
// https://opencv-tutorial.readthedocs.io/en/latest/draw/draw.html\
//
//https://docs.opencv.org/2.4/modules/core/doc/drawing_functions.html?highlight=rectangle#rectangle

//could draw a thick lined rectangle on top of the full reactangle to get outlines for the squares

//thinking of starting at 175, 175, 175 for the "controlled" squares and
// eventually working toward somewhere around 0, 0, 255
//G and B will go down as R goes up


void drawGrid(Tile tiles[], Mat mainImg, int squareSize){
	
	private int startingLocation = 0;
	private int greyValue = 175;
	private int x = startingLocation;
	private int y = startingLocation;
	private int width = 10;
	private int height = 10;
	
	//for loop to itterate through a 1d array like it was a 2d array
	for(int i = 0; i < sizeof(tiles); i++){
		
		//calculations for color of square based off of control
		int gAndB = int(((100.0 - tiles[i].getControl())/100.0) * greyValue);
		int red = int(((100.0 - tiles[i].getControl())/100.0) * (255-greyValue));
		
		cv::Rect rect(x, y, width, height);
		
		cv::rectangle(mainImg, pt1, pt2, cv::Scalar(greyValue-gAndB, greyValue-gAndB, greyValue+red), cv::filled);
		
		
		if(x<size){
			x+=squareSize;
		}else{
			y+=squareSize;
			x = startingLocation;
		}
	}
}
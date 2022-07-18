#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
//#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//with help from https://www.geeksforgeeks.org/draw-an-rectangle-using-opencv-in-cpp/
int main(int argc, char** argv)
{
    // Creating a blank image with
    // white background
    Mat image(1000, 1000, CV_8UC3,
              Scalar(255, 255, 255));
  
    // Check if the image is created
    // successfully or not
    if (!image.data) {
        std::cout << "Could not open or "
                  << "find the image\n";
  
        return 0;
    }
  
    // Top Left Corner
    Point p1(30, 30);
  
    // Bottom Right Corner
    Point p2(255, 255);
  
    int thickness = -1;
  
    // Drawing the Rectangle
	
	//Line_4 does solid edges, Line_8 is similar, Line_AA is with anti-aliasing and attempts to smooth the edges
    rectangle(image, p1, p2,
              Scalar(0, 255, 0),
              thickness, LINE_8);
			  
	//cv::rectangle(image, cv::Point(100, 320), c
  
    // Show our image inside a window
    imshow("Output", image);
    waitKey(0);
  
    return 0;
}


int main(int argc, char** argv){

	int count = 40;
	int size = 1000;
	thickness = 3;
	
	
	int y1 = 0;
	int y2 = size/count;
	
	// Creating a blank image with
    // white background
    Mat image(size, size, CV_8UC3, Scalar(255, 255, 255));
	
	//making a grid of squares 
	for(int j = 0; j < count; j++){
		int x1 = 0;
		int x2 = size/count; 
		for(int i = 0; i < count; i++){
				
			rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2), Scalar(0,255,0), thickness, LINE_4);
			x1 += size/count;
			x2 += size/count;
		
		}
	}
	
}

int main(int argc, char** argv){
	
	int tileCount = 40;
	int tileNumber = 1;
	
	int grid[tileCount][tileCount];
	
	for(int i = 0; i < tileCount; i++){
		for(int j = 0; j < tileCount; j++){
			new Tile(tileNumber, x1, x2, y1, y2, 0);
		}
	}

}
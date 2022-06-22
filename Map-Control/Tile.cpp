#include <iostream>
#include <string>
#include "point.h"

using namespace std;

public class Tile{
	public:
		int x;
		int y;
		
		Tile(int xVal, int yVal, bool con){
			x = xVal;
			y = yVal;
			if(con){
				control = 100.0;
			}else{
				control = 0.0;
			}
			losingCon = false;
		}
		
		double getControl(){
			return control;
		}
		
		void resetControl(){		
			losingCon = false;
			control = 100.0;
		}
		
		Point getPosition(){
			return new Point(x, y);
		}
		
		void updateCon(){
			
		}
		
	private:
		double control;
		bool losingCon;	
		
}

//run speed with knife: 6.75 m/s
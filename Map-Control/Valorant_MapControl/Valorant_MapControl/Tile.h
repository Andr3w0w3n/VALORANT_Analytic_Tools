//this pragma may be causing the name issues?
//#pragma once
#include <iostream>
#include <string>
//#include "Point.h"

using namespace std;

class Tile {
	public:
		int x;
		int y;
		Tile(int xVal, int yVal, double con);
		Tile(void);
		double getControl();
		void resetControl();
		void beginLosingControl();
		void pauseLosingControl();
		void updateCon();

	private:
		double control;
		bool losingCon;
	
	//This was one of the ways of implementing the class constructor
	// https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
	
	/*Tile(const int xVal, const int yVal, double con) : x(xVal), y(yVal), control(con) {
		losingCon = false;
	}
	
	//this is the other*/
	
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
	
	Tile(void) {
		x = -1;
		y = -1;
		control = 100.0;
		losingCon = false;
		cout << "An invalid tile was created";
	}

	double getControl() {
		return control;
	}

	void resetControl() {
		losingCon = false;
		control = 100.0;
	}

	void beginLosingControl() {
		losingCon = true;
	}

	void pauseLosingControl() {
		losingCon = false;
	}

	void updateCon() {
		//this is where the control percentage will be updated
		if(!losingCon){
			
		}
	}

}

//run speed with knife: 6.75 m/s
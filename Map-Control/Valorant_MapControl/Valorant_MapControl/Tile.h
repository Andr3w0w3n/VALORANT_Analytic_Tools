#pragma once
#include <iostream>
#include <string>
//#include "Point.h"

using namespace std;

class Tile {
	public:
		int x;
		int y;

	private:
		double control;
		bool losingCon;

	Tile(const int xVal, const int yVal, double con) : x(xVal), y(yVal), control(con) {
		losingCon = false;
	}

	Tile() {
		x = -1;
		y = -1;
		control = 100.0;
		losingCon = false;
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
	}

}
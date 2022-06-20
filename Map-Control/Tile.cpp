#include <iostream>
#include <string>

using namespace std;

public class Tile{
	public:
		int x;
		int y;
		Point position;
		Tile top;
		Tile topRight;
		Tile topLeft;
		Tile right;
		Tile left;
		Tile bottom;
		Tile bottomRight;
		Tile bottomLeft;
		
	private:
		double control;
		
	
	
	public void setControl(double con){	
		control = con;
	}
	
	public double getControl(){
		return control;
	}
	
	public checkSurroundings(){
		if(control == 100.0){
			top.getControl();
			topRight.getControl();
			topLeft.getControl();
			right.getControl();
			left.getControl();
			bottom.getControl();
			bottomRight.getControl();
			bottomLeft.getControl();
		}
	}
	
	
}
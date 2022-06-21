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
		bool losingCon;
		
	
	
	
	public double getControl(){
		return control;
	}
	
	public checkSurroundings(){
		if(control == 100.0){
			if(top.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(topRight.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(topLeft.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(right.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(left.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(bottom.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(bottomRight.getControl() >= STARTVALUE){
				losingCon = true;
			}else if(bottomLeft.getControl() >= STARTVALUE){
				losingCon = true;
			}
		}
	}
	
	public void resetControl(){		
		losingCon = false;
		control = 100.0;
	}
	
	public void setTop(Tile t){
		top = t;
	}
	
	public void setTopRight(Tile t){
		topRight = t;
	}
	
	public void setTopLeft(Tile t){
		topLeft = t;
	}
	
	public void setRight(Tile t){
		right = t;
	}
	
	public void setLeft(Tile t){
		left = t;
	}
	
	public void setBottom(Tile t){
		bottom = t;
	}
	
	public void setBottomLeft(Tile t){
		bottomLeft = t;
	}
	
	public void setBottomRight(Tile t){
		bottomRight = t;
	}
}

//run speed with knife: 6.75 m/s
public class PositionNode(bool c, int edge, PositionNode left, PositionNode right, PositionNode top, PositionNode bottom){
	private bool control = c;
	private double controlValue = 0.0;
	private int edgeCase = edge;
	
	public onStart(){
		if(control) 
			controlValue = 100.0;
	}
	
	public update(){
		
		int min = 1;
		
		if(!control){
			double lowestValue = 100.00
			
			switch(edgeCase){
				
				case 1:
					if(left.getControlValue() < lowestValue){
						lowestValue = left.getControlValue();
						min = 2;
					}
					if(right.getControlValue() < lowestValue){
						lowestValue = right.getControlValue();
						min = 2;
					}
					if(top.getControlValue() < lowestValue){
						lowestValue = top.getControlValue();
						min = 2;
					}
					if(bottom.getControlValue() < lowestValue){
						lowestValue = bottom.getControlValue();
						min = 2;
					}
					
				case 2:
					if(right.getControlValue() < lowestValue){
						lowestValue = right.getControlValue();
						min = 2;
					}
					if(top.getControlValue() < lowestValue){
						lowestValue = top.getControlValue();
						min = 2;
					}
					if(bottom.getControlValue() < lowestValue){
						lowestValue = bottom.getControlValue();
						min = 2;
					}
					
				case 3:
					if(left.getControlValue() < lowestValue){
						lowestValue = right.getControlValue();
						min = 2;
					}
					if(top.getControlValue() < lowestValue){
						lowestValue = top.getControlValue();
						min = 2;
					}
					if(bottom.getControlValue() < lowestValue){
						lowestValue = bottom.getControlValue();
						min = 2;
					}
			}
			
			
			if(lowestValue >= controlValue){
				min = 1;
			}
		}
		
		switch(min){
			
			case 1:
				break;
			
			case 2:
				controlValue = controlValue - /*VALUE TO BE SUBTRACTED*/;
				
			case 3:
				controlValue = 100.0;
			
			case 4:
				controlValue = 0.0;
		
		}
	}
	
	public setControl(bool con){
		control = con;
		if(control)
			controlValue = 100.0;
	}
	
	public double getControlValue(){
		return controlValue;
	}
	
	public boolean getControl(){
		return control;
	}
	
	private void checkSurroundings(){
		//This is where we will check surrounding squares
		
		switch(edgeCase){
		
			case 1:
				
		
		}
		if(!(left.getControl() && right.getControl() && top.getControl() && bottom.getControl()) && control){
			control = false;
		}
	}
	
	private void modifyControlValue(double val){
		controlValue = val;
	}
}


/*
- Frame by frame looking and changing tiles
- Create arrays of the map objects that have been 100% controlled by the enemy
	- Hash these into array? Use position value for hash function



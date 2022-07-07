#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

//https://www.programiz.com/dsa/graph-adjacency-list
/*// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}*/

void updateConTiles(list<int> adj[], Tile tiles[]){
	//this is where all the tiles will be updated
	for(int i = 0; i < sizeof(adj); i++){
		bool found = false;
		bool end = false;
		bool pause = false;
		//check to see if 
		if(tiles[i].getControl() == 100.0){
			list<int>::iterator object = adj[i].begin();
			do{
				if(object == adj[i].end()){
					end = true;
				}if(tiles[object].getControl() < 100.0){
					found = true;
				}else if(!end){
					object++;
				}
			}while(!found && !end)

		//if tile is in the middle of lowering control, look to see if it needs to pause
		// due to no longer being surrounded by non-controlled tiles. This is in hopes
		// of keeping a "realistic probability" with the tiles if you look away and look back
		}else if(tiles[i].getControl() < 100.0 && tiles[i].getControl() > 0.0){
			list<int>::iterator object = adj[i].begin();
			do{
				if(object == adj[i].end()){
					end = true;
				}if(tiles[object].getControl() < tiles[i].getControl()){
					found = true;
				}else if(!end){
					object++;
				}
			}while(!found && !end)
			if(!found){
				pause = true;
			}
		}
		if(pause && !found){
			tiles[i].pauseLosingControl();
		}else if(found){
			tiles[i].beginLosingControl();
		}
	}
}

bool checkXY(int x, int y){
	
	
	
}

int insertSurroundingNum(int x, int y, int size, int itt){
	
	//itt will be the value of whatever is passed through, as to itterate over the 9
	// potentially surrounding objects. This should help setup a default adjacency list
	// without the out of map points.
	switch(itt){
		//top left
		case 1: 
			if((x-1 != -1) && (y-1 != -1)){
				return size*(y-1) + (x-1);
			}
		
		//top mid
		case 2: 
			if(y-1 != -1){
				return size*(y-1) + (x);
			}
		
		//top right
		case 3: 
			if((x+1 != size) && (y-1 != -1)){
				return size*(y-1) + (x+1);
			}
			
		//left
		case 4: 
			if((x-1 != -1)){
				return size*(y) + (x-1);
			}
		
		//right
		case 5: 
			if((x+1 != size)){
				return size*(y) + (x+1);
			}
			
		//bottom left
		case 6: 
			if((x-1 != -1) && (y+1 != size)){
				return size*(y+1) + (x-1);
			}
			
		//bottom mid
		case 7: 
			if(y+1 != size){
				return size*(y+1) + (x);
			}
			
		//bottom right
		case 8: 
			if((x+1 != size) && (y+1 != size)){
				return size*(y+1) + (x+1);
			}
	return -1;
}

int main(){
	
	const int size = 50;
	const int tileNum = size * size;
	int x = 0;
	int y = 0;
	Tile tiles[tileNum];

	list<int> adj[tileNum];

	//this creates the entire grid of tiles and puts them in a linear array
	//currently this is very rough and includes tiles that will not be used
	for (int i = 0; i < tileNum; i++) {
		checkXY(x, y);
		tiles[i] = new Tile(x, y, true);
		for(int j = 1; j <= 9; j++){
			int val = insertSurroundingNum(x, y, j);
			if(val == -1){
				
			}
			adj[i].insert();
		}
		
		if (x < size) {
			x++;
		}else{
			y++;
			x = 0;
		}
	}

	
	return 0;
}
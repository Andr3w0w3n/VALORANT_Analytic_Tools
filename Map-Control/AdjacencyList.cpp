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
				}if(tiles[object].getControl() < 100.0){
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

int main(){
	
	int size;
	private int tileNum = size * size;
	private int x = 0;
	private int y = 0;
	Tile tiles[tileNum];
	
	list<int> adj[tileNum];
	
	//this creates the entire grid of tiles and puts them in a linear array
	//currently this is very rough and includes tiles that will not be used
	for(int i = 0; i < tileNum; i++){
		tiles[tileNum] = new Tile(x, y, true);
		if(x<size){
			x++;
		}else{
			y++;
			x = 0;
		}
	}
	
	//probably should not do a 2d array due to some of the tiles being deleted, it may be more effecient (space and time) to use a single array\
	// especially with the deletion.
	//Tile tiles[tileNum/2][tileNum/2];
	
	/*for(int i = 0; i < tileNum/2; i++){
		for(int j = 0; j < tileNum/2; j++){
			tiles[j][i] = new Tile(j, i, true);
		}
	}*/
	
	return 0;
}
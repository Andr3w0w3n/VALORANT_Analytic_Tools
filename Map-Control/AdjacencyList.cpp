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

bool checkSurroundings(list<Tile> adj[]){
	
	

}

int main(){
	
	int size;
	private int tileNum = size * size;
	private int x = 0;
	private int y = 0;
	Tile tiles[tileNum];
	
	list<int> adj[tileNum];
	
	//this creates the entire grid of tiles and puts them in a linear array
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
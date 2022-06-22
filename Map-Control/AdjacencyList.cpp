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
	
	int tileNum;
	
	
	list<int> adj[tileNum];
	
	
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
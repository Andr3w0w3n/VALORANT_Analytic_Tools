#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Graph{
    int numVertices;
    list<int> *adjLists;
    
  public:
    Graph(int V);
    void addEdge(int src, int dest);
}



int main(){
	
	int tileNum;
	Tile tiles[tileNum];
	
	vector<int> adj[tileNum];
	
	return 0;
}
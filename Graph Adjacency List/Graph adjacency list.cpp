#include "iostream"
#include "list"
using namespace std;

class Graph{
	int numVertices;
	list<int> *adjList;
	
	public:
		Graph(int V) {
			numVertices = V;
			adjList = new list<int>[V];
		}
		
		void addEdge(int x, int y) {
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		
		void printAdjList() {
			for(int i = 0; i < numVertices; i++) {
				cout << "Vertex " << i << " tetangganya -> ";
				for(int neighbour : adjList[i]) {
					cout << neighbour << ",";
				}
				cout << endl;
			}
		}
};


int main() {
	Graph graph(5);
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);

	
	graph.printAdjList();
	
	return 0;
	
}
#include "graph.hpp"
#include <string>
using namespace std;

// graph class test
int main(void)
{
	graph<string> locationMap;

	// add vertices
	locationMap.addVertex("Seoul");
	locationMap.addVertex("Tokyo");
	locationMap.addVertex("New York");
	locationMap.addVertex("Paris");
	locationMap.addVertex("Nice");
	locationMap.addVertex("Madrid");

	// add edges
	locationMap.addEdge("Seoul", "New York", 24);
	locationMap.addEdge("Seoul", "Madrid", 26);
	locationMap.addEdge("Madrid", "New York", 9);
	locationMap.addEdge("New York", "Tokyo", 30);
	locationMap.addEdge("New York", "Paris", 12);
	locationMap.addEdge("Paris", "Nice", 12);

	cout << "BFS Search" << endl;
	locationMap.printGraphBFS();
	cout << "DFS Search" << endl;
	locationMap.printGrpahDFS();

	locationMap.deleteEdge("Paris", "Nice");
	cout << "BFS Search" << endl;
	locationMap.printGraphBFS();
	cout << "DFS Search" << endl;
	locationMap.printGrpahDFS();

	locationMap.deleteVertex("Paris");
	cout << "BFS Search" << endl;
	locationMap.printGraphBFS();
	cout << "DFS Search" << endl;
	locationMap.printGrpahDFS();
}

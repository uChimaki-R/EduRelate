#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	string filePath;
	cout << "Enter the file path: ";
	cin >> filePath;

	Graph graph;
	graph.readFromFile(filePath);

	char startNode;
	cout << "Enter the start node: ";
	cin >> startNode;

	cout << "BFS traversal: ";
	graph.BFS(startNode);

	cout << endl;

	cout << "DFS traversal: ";
	graph.DFS(startNode);

	return 0;
}

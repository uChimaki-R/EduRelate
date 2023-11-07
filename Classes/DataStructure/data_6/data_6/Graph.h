#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Edge
{
	int st, ed;
	Edge* next;
};

struct Node
{
	char name;
	Edge* first;
};

class Graph {
public:
	int M = 0, N = 0;
	bool isDirected = false;
	map<char, int>NameToIndex;
	const static int MaxSize = 500;
	int ep = 0;
	Node nodes[MaxSize] = {};
	Edge edges[MaxSize] = {};

	Graph() {}

	void addEdge(int a, int b);

	void readFromFile(const string& filePath);

	void BFS(char startNode);

	void DFS(char startNode);

	void DFSUtil(char name, vector<bool>& visited);
};

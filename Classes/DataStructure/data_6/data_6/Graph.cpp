#include"Graph.h"

void Graph::addEdge(int a, int b) {
	edges[ep].st = a;
	edges[ep].ed = b;
	edges[ep].next = nodes[a].first;
	nodes[a].first = &edges[ep];
	ep++;
}

void Graph::readFromFile(const string& filePath) {
	ifstream inFile(filePath);
	if (!inFile.is_open()) {
		cerr << "Error: File not found or path is incorrect." << endl;
		exit(1);
	}

	inFile >> M >> N;
	inFile >> isDirected;

	for (int i = 0; i < M; i++) {
		char name;
		inFile >> name;
		NameToIndex.insert(make_pair(name, i));
		nodes[i].name = name;
	}

	for (int i = 0; i < N; i++) {
		char P1, P2;
		inFile >> P1 >> P2;
		addEdge(NameToIndex[P1], NameToIndex[P2]);

		if (!isDirected) {
			addEdge(NameToIndex[P2], NameToIndex[P1]);
		}
	}
	inFile.close();
}

void Graph::BFS(char startNode) {
	vector<bool> visited(M, false);
	queue<char> q;
	q.push(startNode);

	while (!q.empty()) {
		char front = q.front();
		q.pop();
		cout << front << " ";
		visited[NameToIndex[front]] = true;
		Edge* e = nodes[NameToIndex[front]].first;
		while (e) {
			int index = e->ed;
			if (!visited[index]) {
				visited[index] = true;
				q.push(nodes[e->ed].name);
			}
			e = e->next;
		}
	}
}

void Graph::DFS(char startNode) {
	vector<bool> visited(M, false);
	DFSUtil(startNode, visited);
}

void Graph::DFSUtil(char name, vector<bool>& visited) {
	cout << name << " ";
	Edge* e = nodes[NameToIndex[name]].first;
	while (e) {
		int index = e->ed;
		if (!visited[index]) {
			visited[index] = true;
			DFSUtil(nodes[e->ed].name, visited);
		}
		e = e->next;
	}
}

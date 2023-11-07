#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

const int MaxSize = 500;
int ep;

struct Edge
{
    int st, ed;
    Edge* next;
}edges[MaxSize];

struct Node
{
    Edge* first;
}nodes[MaxSize];

void addEdge(int a, int b) {
    edges[ep].st = a;
    edges[ep].ed = b;
    edges[ep].next = nodes[a].first;
    nodes[a].first = &edges[ep];
    ep++;
}

class Graph {
public:
    int M, N;
    bool isDirected;
    map<char, int>NameToIndex;

    Graph() {}

    void readFromFile(const string& filePath) {
        ifstream inFile(filePath);
        if (!inFile.is_open()) {
            cerr << "Error: File not found or path is incorrect." << endl;
            exit(1);
        }

        inFile >> M >> N;
        inFile >> isDirected;

        for (int i = 0; i < M; ++i) {
            char name;
            inFile >> name;
            NameToIndex.insert(make_pair(name, i));
        }

        for (int i = 0; i < N; ++i) {
            char P1, P2;
            inFile >> P1 >> P2;
            int index1 = find(nodes.begin(), nodes.end(), P1) - nodes.begin();
            int index2 = find(nodes.begin(), nodes.end(), P2) - nodes.begin();

            if (isDirected) {
                adjMatrix[index1][index2] = 1;
                adjList[{P1, P2}].insert(P2);
            }
            else {
                adjMatrix[index1][index2] = 1;
                adjMatrix[index2][index1] = 1;
                adjList[{P1, P2}].insert(P1);
                adjList[{P1, P2}].insert(P2);
            }
        }

        inFile.close();
    }

    void BFS(char startNode) {
        vector<bool> visited(M, false);
        queue<char> q;
        q.push(startNode);
        visited[find(nodes.begin(), nodes.end(), startNode) - nodes.begin()] = true;

        while (!q.empty()) {
            char currentNode = q.front();
            q.pop();
            cout << currentNode << " ";

            for (int i = 0; i < M; ++i) {
                if (adjMatrix[find(nodes.begin(), nodes.end(), currentNode) - nodes.begin()][i] == 1 && !visited[i]) {
                    q.push(nodes[i]);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void DFS(char startNode) {
        vector<bool> visited(M, false);
        DFSUtil(startNode, visited);
    }

    void DFSUtil(char node, vector<bool>& visited) {
        visited[find(nodes.begin(), nodes.end(), node) - nodes.begin()] = true;
        cout << node << " ";

        for (char neighbor : adjList[{node, ' '}]) {
            if (!visited[find(nodes.begin(), nodes.end(), neighbor) - nodes.begin()]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

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

    cout << "DFS traversal: ";
    graph.DFS(startNode);

    return 0;
}

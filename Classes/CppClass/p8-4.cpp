#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>>& graph, vector<int>& result) {
	int n = graph.size();
	vector<int> inDegree(n, 0);

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			++inDegree[graph[i][j]];
		}
	}

	queue<int> q;
	for (int i = 1; i < n; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		result.push_back(u);

		for (int v : graph[u]) {
			--inDegree[v];
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	vector<int> result;
	topologicalSort(graph, result);

	for (int u : result) {
		cout << u << " ";
	}
	cout << endl;

	return 0;
}

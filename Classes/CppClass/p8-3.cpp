#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(const vector<vector<pii>>& graph, int start) {
	int n = graph.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u]) continue;
		visited[u] = true;

		for (const auto& edge : graph[u]) {
			int v = edge.first;
			int w = edge.second;

			if (!visited[v] && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}

	return dist;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pii>> graph(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	int start;
	cin >> start;

	vector<int> dist = dijkstra(graph, start);

	for (int i = 1; i <= n; ++i) {
		cout << "从顶点 " << start << " 到顶点 " << i << " 的最短路径长度为： " << dist[i] << endl;
	}

	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

const int N = 3010;
int ways[N][N];

struct Node {
	vector<int>next;
}nodes[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int st, ed;
		cin >> st >> ed;
		nodes[st].next.emplace_back(ed);
	}
	for (int i = 1; i <= n; i++) {
		for (int next : nodes[i].next) {
			for (int nnext : nodes[next].next) {
				if (nnext != i)ways[i][nnext]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += ways[i][j] * (ways[i][j] - 1) / 2;
		}
	}
	cout << ans;
	return 0;
}
#include<iostream>
#include<queue>
using namespace std;

const int N = 100007;
int n, m, ep;
bool check;

struct Edge {
	int st, ed, len;
	Edge* next;
}edges[N];

struct Node {
	Edge* first;
}nodes[N];

void addedge(int a, int b, int len) {
	edges[ep].st = a;
	edges[ep].ed = b;
	edges[ep].len = len;
	edges[ep].next = nodes[a].first;
	nodes[a].first = &edges[ep];
	ep++;
}

void dfs(int i) {
	Edge* e = nodes[i].first;
	int nextP = 0, maxLen = 0;
	while (e) {
		if (maxLen < e->len) {
			maxLen = e->len;
			nextP = e->ed;
		}
		e = e->next;
	}
	if (maxLen) {
		check = true;
		cout << nextP << " " << maxLen << endl;
		dfs(nextP);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		addedge(a, b, len);
	}
	dfs(1);
	if (!check) {
		cout << "none" << endl;
	}
	return 0;
}

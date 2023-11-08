#include<iostream>
#include<queue>
using namespace std;

const int N = 100007;
int n, m, ep;

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

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		addedge(a, b, len);
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0, len = 0;
		Edge* e = nodes[i].first;
		while (e) {
			if (e->len > len) {
				len = e->len;
				ans = e->ed;
			}
			e = e->next;
		}
		if (ans) {
			cout << ans << " " << len << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}

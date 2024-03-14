#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define pii pair<int, int>

const int N = 100007;
int n, m, ep, maxCount, counts[N];

struct Edge {
	int st, ed, len;
	Edge* next;
}edges[N];

struct Node {
	Edge* first;
}nodes[N];

void addedge(int a, int b, int len) {
	counts[a]++;
	maxCount = max(maxCount, counts[a]);
	edges[ep].st = a;
	edges[ep].ed = b;
	edges[ep].len = len;
	edges[ep].next = nodes[a].first;
	nodes[a].first = &edges[ep];
	ep++;
}

bool mySort(const pii& p1, const pii& p2) {
	if (p1.first != p2.first)return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		addedge(a, b, len);
	}
	for (int i = 1; i <= n; i++) {
		if (counts[i] == maxCount) {
			cout << i << endl;
			Edge* e = nodes[i].first;
			vector<pii>ve;
			while (e) {
				ve.push_back(make_pair(e->ed, e->len));
				e = e->next;
			}
			sort(ve.begin(), ve.end(), mySort);
			for (auto p : ve) {
				cout << p.first << " " << p.second << endl;
			}
			break;
		}
	}
	return 0;
}

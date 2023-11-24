#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

const int N = 200007;
int n, tail = 1, a[N], dis[N], que[N];
vector<int>son[N];
int qwq[1000007];

int main() {
	memset(qwq, -1, sizeof(qwq));
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = n; i > 0; i--) {
		if (qwq[a[i]] != -1) son[i].push_back(qwq[a[i]]);
		qwq[a[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		son[i].push_back(i + 1);
		son[i + 1].push_back(i);
	}
	que[1] = dis[1] = 1;
	for (int i = 1; i <= n; i++) {
		int cur = que[i];
		for (auto v : son[cur])
			if (dis[v] == 0) {
				dis[v] = dis[cur] + 1;
				que[++tail] = v;
			}
	}
	cout << dis[n] - 1;
	return 0;
}

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int N = 1507;

int n, s1, s2, c[N], f[N], ans;
vector<int> son[N];
int dis[N];

void dfs1(int cur, int fa) {
	for (auto i : son[cur]) if (i != fa) {
		dis[i] = dis[cur] + 1;
		dfs1(i, cur);
	}
}

void dfs3(int cur, int fa, int rest, int sum) {
	if (c[cur] == 0) return;
	int qwq = min(max(c[cur] - f[cur], 0), rest);
	rest -= qwq, sum += qwq + min(c[cur], f[cur]);
	ans = max(ans, sum);
	for (auto i : son[cur]) if (i != fa) {
		f[i] += 1;
		dfs3(i, cur, rest, sum);
		f[i] -= 1;
	}
}

void dfs2(int cur, int fa, int len) {
	if (len <= dis[cur]) {
		dfs3(cur, 0, dis[cur] - len, 0);
	}
	for (auto i : son[cur]) if (i != fa) {
		f[i] += 1;
		dfs2(i, cur, len + 1);
		f[i] -= 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		son[u].push_back(v), son[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	scanf("%d%d", &s1, &s2);
	dfs1(s1, 0);
	dfs2(s2, 0, 0);
	cout << ans << endl;
}

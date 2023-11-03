#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<cstdio>
#include<climits>
#include<vector>
using namespace std;
#define int long long

const int N = 50000;
int ton[N], tot[N], tof[N], vis[N];
int te, fe, s, t, f, n, m, ans = LLONG_MAX;

struct Node
{
	vector<int>next;
}nodes[N];

void dfs(int& start, int dis[], int times)
{
	queue<int>qu;
	vis[start]++;
	qu.push(start);
	while (!qu.empty())
	{
		int front = qu.front();
		qu.pop();
		for (auto next : nodes[front].next)
		{
			if (vis[next] != times)
			{
				dis[next] = dis[front] + 1;
				vis[next]++;
				qu.push(next);
			}
		}
	}
}

signed main()
{
	scanf("%lld %lld %lld %lld %lld %lld %lld", &te, &fe, &s, &t, &f, &n, &m);
	for (int i = 0; i < m; i++)
	{
		int st, ed;
		scanf("%lld %lld", &st, &ed);
		nodes[st].next.push_back(ed);
		nodes[ed].next.push_back(st);
	}
	dfs(n, ton, 1);
	if (!vis[t] || !vis[f])
	{
		printf("-1");
		return 0;
	}
	dfs(t, tot, 2);
	dfs(f, tof, 3);
	int tfe = te + fe - s;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 3)
		{
			ans = min(ans, te * tot[i] + fe * tof[i] + tfe * ton[i]);
		}
	}
	printf("%lld", ans);
	return 0;
}
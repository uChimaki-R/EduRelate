#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int N = 80010;
int te, fe, s, t, f, n, m, ep;
int dis[3][N];

struct Edge
{
	int st, ed;
	Edge* next;
}edges[N];

struct Node
{
	Edge* first;
}nodes[N];

void addEdge(int a, int b) {
	edges[ep].st = a;
	edges[ep].ed = b;
	edges[ep].next = nodes[a].first;
	nodes[a].first = &edges[ep];
	ep++;
}

void getDis(int* arr, int st) {
	memset(arr, -1, sizeof(int[N]));
	arr[st] = 0;
	queue<int>qu;
	qu.push(st);
	while (!qu.empty()) {
		int front = qu.front();
		qu.pop();
		Edge* eg = nodes[front].first;
		while (eg) {
			if (arr[eg->ed] == -1) {
				arr[eg->ed] = arr[eg->st] + 1;
				qu.push(eg->ed);
			}
			eg = eg->next;
		}
	}
}

int main() {
	cin >> te >> fe >> s;
	cin >> t >> f >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		addEdge(a, b);
		addEdge(b, a);
	}
	getDis(dis[0], t);
	getDis(dis[1], f);
	getDis(dis[2], n);
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < N; j++)
			cout << dis[i][j] << " ";
		cout << endl;
	}*/
	long long ans = 1e18;
	for (int i = 1; i <= n; i++) {
		if (dis[0][i] != -1 && dis[1][i] != -1 && dis[2][i] != -1)
			ans = min(ans, 1ll * dis[0][i] * te + 1ll * dis[1][i] * fe + 1ll * dis[2][i] * (te + fe - s));
	}
	if (ans != 1e18)cout << ans;
	else cout << -1;
	return 0;
}
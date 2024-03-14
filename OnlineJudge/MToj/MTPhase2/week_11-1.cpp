#include<iostream>
#include<algorithm>
using namespace std;

const int N = 107;
int f[N];

struct Node
{
	int i, j, c;
	bool operator<(const Node& node)
	{
		return this->c < node.c;
	}
}nodes[N];

int find(int i)
{
	return f[i] == i ? i : f[i] = find(f[i]);
}

void merge(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
	{
		f[fb] = fa;
	}
}

int main()
{
	int n, k, a, b, c;
	cin >> n >> k;
	for (int i = 1; i < N; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> nodes[i].i >> nodes[i].j >> nodes[i].c;
	}
	sort(nodes, nodes + k);
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		if (find(nodes[i].i) != find(nodes[i].j))
		{
			ans += nodes[i].c;
			merge(nodes[i].i, nodes[i].j);
		}
	}
	cout << ans;
	return 0;
}
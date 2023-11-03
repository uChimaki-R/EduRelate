#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 10007;

int f[N];

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
		f[fa] = fb;
	}
}

struct Edge
{
	int beg, end, len;
	bool operator<(const Edge& e)
	{
		return this->len < e.len;
	}
}edge[N], ans[N];

bool cmp(const Edge& edge1, const Edge& edge2)
{
	if (edge1.beg == edge2.beg)
	{
		return edge1.end < edge2.end;
	}
	return edge1.beg < edge2.beg;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(ans, 0, sizeof(ans));
		memset(edge, 0, sizeof(edge));
		memset(f, 0, sizeof(f));
		int n, len, cnt = 0;
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			f[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> len;
				if (i < j)
				{
					cnt++;
					edge[cnt].beg = i;
					edge[cnt].end = j;
					edge[cnt].len = len;
				}
			}
		}
		sort(edge + 1, edge + 1 + cnt);
		int m = 0;
		for (int i = 1; i <= cnt; i++)
		{
			if (find(edge[i].beg) != find(edge[i].end))
			{
				merge(edge[i].beg, edge[i].end);
				ans[++m] = edge[i];
			}
		}
		sort(ans + 1, ans + 1 + m, cmp);
		cout << m << endl;
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i].beg << " " << ans[i].end << endl;
		}
	}
	return 0;
}
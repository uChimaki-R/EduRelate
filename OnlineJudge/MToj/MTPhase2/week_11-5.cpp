#include<iostream>
using namespace std;

const int N = 100010;

int f[N], cnt[N];

int find(int i)
{
	if (f[i] == i)
	{
		return i;
	}
	return f[i] = find(f[i]);
}

void merge(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
	{
		f[fb] = fa;
		cnt[fa] += cnt[fb];//后续不用遍历相加，优化运行速度
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> cnt[i];
		f[i] = i;
	}
	int opr, a, b;
	while (m--)
	{
		cin >> opr;
		if (opr == 1)
		{
			cin >> a >> b;
			merge(a, b);
		}
		else
		{
			cin >> a;
			cout << cnt[find(a)] << endl;
		}
	}
	return 0;
}

//#include<iostream>
//using namespace std;
//
//const int N = 100010;
//
//int f[N], cnt[N];
//
//int find(int i)
//{
//	if (f[i] == i)
//	{
//		return i;
//	}
//	return f[i] = find(f[i]);
//}
//
//void merge(int a, int b)
//{
//	int fa = find(a);
//	int fb = find(b);
//	if (fa != fb)
//	{
//		f[fb] = fa;
//	}
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> cnt[i];
//		f[i] = i;
//	}
//	int opr, a, b;
//	while (m--)
//	{
//		cin >> opr;
//		if (opr == 1)
//		{
//			cin >> a >> b;
//			merge(a, b);
//		}
//		else
//		{
//			cin >> a;
//			int fa = find(a);
//			int ans = 0;
//			for (int i = 1; i <= n; i++)
//			{
//				if (find(i) == fa)
//				{
//					ans += cnt[i];
//				}
//			}
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}
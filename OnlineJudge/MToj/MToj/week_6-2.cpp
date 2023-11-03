#include<iostream>
#include<string.h>
using namespace std;

int n, m;
const int N = 1e6 + 7;
int rooms[N];
int sub[N];
int temp[N];

struct Order
{
	int x, y, d;
}order[N];

bool check(int pos)
{
	memcpy(temp, sub, sizeof(sub));
	for (int i = 0; i <= pos; i++)
	{
		temp[order[i].x] -= order[i].d;
		temp[order[i].y + 1] += order[i].d;
	}
	for (int i = 1; i < n; i++)
	{
		temp[i] += temp[i - 1];
		if (temp[i] < 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	cin >> rooms[0];
	sub[0] = rooms[0];
	for (int i = 1; i < n; i++)
	{
		cin >> rooms[i];
		sub[i] = rooms[i] - rooms[i - 1];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> order[i].d >> order[i].x >> order[i].y;
	}
	int left = 0;
	int right = m - 1;
	int ans = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (!check(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (check(m - 1))
	{
		cout << 0;
	}
	else
	{
		cout << -1 << endl << ans + 1;
	}
	return 0;
}



//以下方法有一个点超时，采用二分优化


//#include<iostream>
//#include<string.h>
//using namespace std;
//
//int n, m;
//const int N = 1e6 + 7;
//int rooms[N];
//int sub[N];
//int temp[N];
//
//bool check(int x, int y, int d)
//{
//	memcpy(temp, sub, sizeof(sub));
//	temp[x] -= d;
//	sub[x] -= d;
//	temp[y + 1] += d;
//	sub[y + 1] += d;
//	for (int i = 1; i < n; i++)
//	{
//		temp[i] += temp[i - 1];
//		if (temp[i] < 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	cin >> n >> m;
//	cin >> rooms[0];
//	sub[0] = rooms[0];
//	for (int i = 1; i < n; i++)
//	{
//		cin >> rooms[i];
//		sub[i] = rooms[i] - rooms[i - 1];
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int d, x, y;
//		cin >> d >> x >> y;
//		if (!check(x - 1, y - 1, d))
//		{
//			cout << -1 << endl << i + 1;
//			return 0;
//		}
//	}
//	cout << 0;
//	return 0;
//}
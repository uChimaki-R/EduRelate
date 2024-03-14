#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 1010;
int dis[N], arr[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = i + 1; j <= n + 1; j++)
		{
			cin >> arr[i][j];
			dis[i] = INF;
		}
	}
	for (int i = n; i >= 0; i--)
	{
		for (int j = i + 1; j <= n + 1; j++)
		{
			dis[i] = min(dis[i], dis[j] + arr[i][j]);
		}
	}
	cout << dis[0];
	return 0;
}
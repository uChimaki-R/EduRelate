#include<iostream>
#include<vector>
using namespace std;

const int N = 10010;
int f[N], v[N], w[N], n, T, path[N][N];

int main()
{
	cin >> n >> T;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = T; j >= w[i]; j--)
		{
			if (f[j] < f[j - w[i]] + v[i])
			{
				f[j] = f[j - w[i]] + v[i];
				path[i][j] = 1;
			}
		}
	}
	cout << f[T] << endl;
	vector<int>v;
	int i = n - 1, j = T;
	while (i >= 0 && j)
	{
		if (path[i][j])
		{
			v.push_back(i);
			j -= w[i];
		}
		i--;
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i] + 1 << " ";
	}
	return 0;
}
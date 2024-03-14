#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 100010;
vector<int>ans;
int f[550], arr[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	memset(f, INF, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 550; j++)
		{
			if (f[j] < arr[i])
			{
				f[j ^ arr[i]] = min(f[j ^ arr[i]], arr[i]);
			}
		}
	}
	for (int i = 0; i < 550; i++)
	{
		if (f[i] != INF)
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)
	{
		cout << i << " ";
	}
	return 0;
}
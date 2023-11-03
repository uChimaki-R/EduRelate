#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 40;
int arr[N];
int flag, cnt;
bool vis[N];

void dfs(int pos, int num, int sum)
{
	if (num == 0)
	{
		for (int i = pos; i < cnt; i++)
		{
			if (arr[i] == sum)
			{
				flag = 1;
				for (int j = 0; j < i; j++)
				{
					if (vis[j])
					{
						if (sum == arr[j])
						{
							cout << arr[j] << "=" << arr[i] << endl;
							break;
						}
						else
						{
							cout << arr[j] << "+";
						}
						sum -= arr[j];
					}
				}
			}
			if (sum <= arr[i])
			{
				break;
			}
		}
	}
	else
	{
		for (int i = pos; i < cnt; i++)
		{
			if (sum + arr[i] <= arr[cnt - 1])
			{
				vis[i] = true;
				dfs(i + 1, num - 1, sum + arr[i]);
				vis[i] = false;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> cnt;
		memset(arr, 0, sizeof(arr));
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < cnt; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + cnt);
		flag = 0;
		for (int i = 2; i < cnt; i++)
		{
			dfs(0, i, 0);
		}
		if (!flag)
		{
			cout << "Can't find any equations." << endl;
		}
		cout << endl;
	}
	return 0;
}
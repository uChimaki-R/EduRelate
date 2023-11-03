#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int arr[1005];
int ret[1005];
int n, k;

int main()
{
	cin >> n >> k;
	cin >> arr[0];
	ret[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		sort(arr, arr + i);
		for (int j = 0; j < i; j++)
		{
			//和已有的位置逐个对比
			if (abs(arr[j] - arr[i]) < k)
			{
				arr[i] = arr[j] + k;
			}
		}
		ret[i] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << ret[i];
	}
	return 0;
}
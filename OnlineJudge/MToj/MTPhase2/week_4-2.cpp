#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000005];
int n, k;

bool is_k(int dif)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (((arr[i] - arr[j]) > dif) && i > j)
		{
			j++;
		}
		cnt += i - j;
	}
	return cnt >= k;
}

int main()
{
	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int r = arr[n - 1] - arr[0];//最大差
	int l = 0;//最小差
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (is_k(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
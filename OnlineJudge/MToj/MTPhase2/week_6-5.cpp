#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
LL arr[N];
LL ans;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		ans += abs(arr[n / 2] - arr[i]);
	}
	cout << ans;
	return 0;
}
#include<iostream>
using namespace std;

int arr[5005];
int dif[5005];

int main()
{
	int input, ans = 0;
	int cnt = 1;
	arr[0] = -10000;
	while (cin >> input)
	{
		arr[cnt] = input;
		dif[cnt] = arr[cnt] - arr[cnt - 1];
		cnt++;
	}
	int l = 1;
	int r = 2;
	int flag = 0;
	while (r < cnt)
	{
		while (r < cnt && dif[r] == dif[l])
		{
			r++;
			flag = 1;
		}
		if (flag)
		{
			ans += ((r - l) * (r - l - 1) / 2);
		}
		l = r;
		r++;
		flag = 0;
	}
	cout << ans;
	return 0;
}
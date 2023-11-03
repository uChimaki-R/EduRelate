#include<iostream>
using namespace std;

const int N = 100007;
int a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int mmin = 1e9, mmax = 0;//降序最小值和升序最大值
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= mmax && a[i] <= mmin)
			//贪心：该数能去升序数组和降序数组，并且与后面的数能组成升序的话优先去升序，否则后一个数的选择会变少（只有可能去升序）
			if (a[i + 1] >= a[i])mmax = a[i];
			else mmin = a[i];
		else if (a[i] >= mmax)mmax = a[i];
		else if (a[i] <= mmin)mmin = a[i];
		else
		{
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;
}
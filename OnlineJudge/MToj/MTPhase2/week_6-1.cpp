#include<iostream>
using namespace std;

int cnt1, cnt2, x, y;

//cnt1+cnt2不超过2e9
//对于V以内的数，A有V/x个数不能选，B有V/y个数不能选
//要求A、B可选数大于要求数

int main()
{
	cin >> cnt1 >> cnt2 >> x >> y;
	int left = 0;
	int right = 2e9;
	int ans = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		//A可选数大于要求数 && B可选数大于要求数 && A、B都可选的数大于要求数和
		if ((mid - mid / x) >= cnt1 && (mid - mid / y) >= cnt2 && (mid - mid / (x * y)) >= (cnt1 + cnt2))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
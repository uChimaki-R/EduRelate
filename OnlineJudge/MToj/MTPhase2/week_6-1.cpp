#include<iostream>
using namespace std;

int cnt1, cnt2, x, y;

//cnt1+cnt2������2e9
//����V���ڵ�����A��V/x��������ѡ��B��V/y��������ѡ
//Ҫ��A��B��ѡ������Ҫ����

int main()
{
	cin >> cnt1 >> cnt2 >> x >> y;
	int left = 0;
	int right = 2e9;
	int ans = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		//A��ѡ������Ҫ���� && B��ѡ������Ҫ���� && A��B����ѡ��������Ҫ������
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
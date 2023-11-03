#include<iostream>
using namespace std;

int mp[100005];
int ans = 0;

int main()
{
	int n;
	cin >> n;
	mp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> mp[i];
	}
	for (int i = 2; i <= n; i++)
	{
		if (mp[i] && mp[i - 1] && mp[i] != mp[i - 1])
		{
			ans++;
			mp[i] = 0;
		}
	}
	cout << ans;
	return 0;
}


//以下想法出现问题，举例情况是：0112222
//按我之前的想法破坏是1和2中出现少的
//但实际上只用破坏第二个1就可以了，故一直wa


//#include<iostream>
//using namespace std;
//
//int mp[100005];
//int n, ans = 0;
//
//void goon(int pos)
//{
//	while (mp[pos] == 0 && pos <= n)
//	{
//		//找第一个不是0的位置
//		pos++;
//	}
//	if (pos == n + 1)
//	{
//		return;
//	}
//	int color = mp[pos];
//	int tpos = pos;
//	while (mp[tpos] == color && tpos <= n)
//	{
//		//找到第一个不是color的位置
//		tpos++;
//	}
//	if (tpos == n + 1)
//	{
//		return;
//	}
//	if (mp[tpos] == 0)
//	{
//		//这一段都可以跳过
//		return goon(tpos);
//	}
//	else
//	{
//		//遇到了另外的color的位置
//		int cnt1 = 0, cnt2 = 0;
//		while (mp[pos] != 0 && pos <= n)
//		{
//			//扫描这部分的1、2分布情况
//			if (mp[pos] == 1)
//			{
//				cnt1++;
//			}
//			else
//			{
//				cnt2++;
//			}
//			pos++;
//		}
//		//破坏较少的
//		ans += min(cnt1, cnt2);
//		goon(pos);
//		return;
//	}
//}
//
//int main()
//{
//	cin >> n;
//	mp[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> mp[i];
//	}
//	goon(0);
//	cout << ans;
//	return 0;
//}
#include<iostream>
using namespace std;

int damage[100005];

int main()
{
	int n, k, b;
	cin >> n >> k >> b;
	for (int i = 0; i < b; i++)
	{
		int input;
		cin >> input;
		damage[input] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		damage[i] += damage[i - 1];
	}
	int min_r = 0x3f3f3f;
	for (int i = 1; i + k - 1 <= n; i++)
	{
		min_r = min(min_r, damage[i + k - 1] - damage[i - 1]);
	}
	cout << min_r;
	return 0;
}






//使用深搜会超时，上面为差分做法

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//bool is_damage[100005];
//int n, k, b, input, min_r = 0x3f3f3f;
//
////看到第pos栈灯 目前一共有cnt个连续灯 已经修了repair栈灯
//void dfs(int pos, int cnt, int repair)
//{
//	if (repair >= min_r)
//	{
//		return;
//	}
//	while (pos < n && !is_damage[pos])
//	{
//		pos++;
//		cnt++;
//	}
//	if (cnt >= k)
//	{
//		min_r = min(min_r, repair);
//		return;
//	}
//	else if (cnt + 1 >= k)
//	{
//		min_r = min(min_r, repair + 1);
//		return;
//	}
//	if (pos != n)
//	{
//		//修理这个灯的情况
//		dfs(pos + 1, cnt + 1, repair + 1);
//		//不修这个灯的情况,只能从后面重新开始
//		dfs(pos + 1, 0, 0);
//	}
//	else
//	{
//		//看最后一个灯修了够不够
//		if (cnt + 1 >= k)
//		{
//			min_r = min(min_r, repair + 1);
//		}
//		return;
//	}
//}
//
//int main()
//{
//	scanf("%d %d %d", &n, &k, &b);
//	for (int i = 0; i < b; i++)
//	{
//		scanf("%d", &input);
//		is_damage[input] = true;
//	}
//	dfs(1, 0, 0);
//	printf("%d", min_r);
//	return 0;
//}
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


//�����뷨�������⣬��������ǣ�0112222
//����֮ǰ���뷨�ƻ���1��2�г����ٵ�
//��ʵ����ֻ���ƻ��ڶ���1�Ϳ����ˣ���һֱwa


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
//		//�ҵ�һ������0��λ��
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
//		//�ҵ���һ������color��λ��
//		tpos++;
//	}
//	if (tpos == n + 1)
//	{
//		return;
//	}
//	if (mp[tpos] == 0)
//	{
//		//��һ�ζ���������
//		return goon(tpos);
//	}
//	else
//	{
//		//�����������color��λ��
//		int cnt1 = 0, cnt2 = 0;
//		while (mp[pos] != 0 && pos <= n)
//		{
//			//ɨ���ⲿ�ֵ�1��2�ֲ����
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
//		//�ƻ����ٵ�
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
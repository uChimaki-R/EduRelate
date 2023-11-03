#include<iostream>
using namespace std;

//目标是尽量保持高位数不变, 修改右边的数使整个数字回文

int main()
{
	string s;
	cin >> s;
	//去除前置0
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	int left = 0;
	int right = s.length() - 1;
	while (left <= right)
	{
		if (s[left] > s[right])
		{
			//左边大于右边, 右边要向前取10然后变成和左边一样的数
			int pos = right - 1;
			//找到前面第一个不是0的数(借数)
			while (s[pos] == '0')
			{
				//是0只能再向前借数, 自己改为9
				s[pos] = '9';
				pos--;
			}
			s[pos]--;//借数-1
		}
		//如果是右边大于左边直接改右边的数就行
		s[right] = s[left];//改数
		left++;
		right--;
	}
	//最后如果有前置0, 说明遇到了如1000这种借数借到了最高位的情况, 会输出0990, 特判为999
	if (s[0] == '0')
	{
		for (int i = 0; i < s.length() - 1; i++)
		{
			cout << 9;
		}
	}
	else
	{
		cout << s;
	}
	return 0;
}

//int main()
//{
//	string s;
//	cin >> s;
//	while (s[0] == '0')
//	{
//		s.erase(0, 1);
//	}
//	int left = s.length() / 2;
//	int right = left;
//	if (!(s.length() % 2))
//	{
//		left--;
//	}
//	while (left >= 0 && right <= s.length() - 1)
//	{
//		s[left] = s[right] = min(s[left], s[right]);
//		left--;
//		right++;
//	}
//	cout << s;
//	return 0;
//}
#include<iostream>
using namespace std;

//这题分别计数头朝上的三角形个数和头朝下的三角形个数。
// 将三角形n等份后，最小的三角形边长计为1。
//1.头朝上：
//以n = 4为例
//边长为1的三角形个数s1 = 1 + 2 + 3 + 4;
//            i = 2, s2 = 1 + 2 + 3;
//            i = 3, s3 = 1 + 2;
//            i = 4, s4 = 1;
//由此可以得出si = (n - i + 1)(n - i + 2) / 2;
//所以头朝上的即为i = 1到i = n的si求和；
//2.头朝下 ：
//n = 1, s = 0;
//n = 2, s = 0 + 1;
//n = 3, s = 0 + 1 + 2;
//n = 4, s = 0 + 1 + (1 + 2 + 3);
//n = 5, s = 0 + (1 + 2) + (1 + 2 + 3 + 4）;
//n = 6, s = 0 + 1 + (1 + 2 + 3) + (1 + 2 + 3 + 4 + 5);
//由此可以推出f(n) = (1 + … + n - i) + f(n - 2);

int up_num(int n)
{
	int up = 0;
	//边长从1到n
	for (int i = 1; i <= n; i++)
	{
		//该边长三角形个数
		int num_i = 0;
		for (int j = 1; j <= n - i + 1; j++)
		{
			num_i += j;
		}
		up += num_i;
	}
	return up;
}

int down_num(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	int down = 0;
	for (int i = 1; i < n; i++)
	{
		down += i;
	}
	return down + down_num(n - 2);
}

int num(int n)
{
	return up_num(n) + down_num(n);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		cout << num(n) << endl;
	}
	return 0;
}

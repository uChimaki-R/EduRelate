#include<iostream>
#include<windows.h>
using namespace std;
void hannota(int, char, char, char);
void move(char, char);
int count1 = 0;
int main()
{
	int n = 0;
	cin >> n;
	hannota(n, 'x', 'y', 'z');
	cout << "一共进行了" << count1 << "步" << endl;
	return 0;
}
void hannota(int n, char x, char y, char z)
{
	if (n == 1)
	{
		move(x, z);
	}
	else
	{
		hannota(n - 1, x, z, y);
		move(x, z);
		hannota(n - 1, y, x, z);
	}
}
void move(char x, char y)
{
	if (count1 % 5 == 0)
	{
		cout << endl;
	}
	cout << count1+1 << "、" << x << " ---> " << y << "      ";
	Sleep(100);
	count1++;
}
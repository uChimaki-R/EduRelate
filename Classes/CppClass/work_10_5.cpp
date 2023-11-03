//1.输出两个数的平均值
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cin >> a >> b;
//	cout << "avg = " << (a + b) / 2.0;
//	return 0;
//}


//2.交换两个数的值
//法1：创建临时变量
//#include<iostream>
//using namespace std;
//void Change(int* a, int* b)
//{
//	int c = 0;
//	c = *a;
//	*a = *b;
//	*b = c;
//}
//int main()
//{
//	int a = 6;
//	int b = 5;
//	cout << "a =" << a << endl;
//	cout << "b =" << b << endl;
//	Change(&a, &b);
//	cout << "————更改后————\n";
//	cout << "a =" << a << endl;
//	cout << "b =" << b;
//	return 0;
//}


//法2：运用按位异或
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 6;
//	int b = 5;
//	cout << "a =" << a << endl;
//	cout << "b =" << b << endl;
//	a = a ^ b;
//	b = a ^ b;
//	a = b ^ a;
//	cout << "————更改后————\n";
//	cout << "a =" << a << endl;
//	cout << "b =" << b;
//	return 0;
//}



//3.计算本息余额
//#include<iostream>
//using namespace std;
//float Calculate(float x, float year)
//{
//	if (year > 1)
//	{
//		return Calculate((1 + 0.033) * x, year - 1);
//	}
//	else
//	{
//		return (1 + 0.033) * x;
//	}
//}
//int main()
//{
//	float x = 0;
//	float year = 0;
//	cout << "请输入本金数目和转存年数：>\n";
//	cin >> x >> year;
//	float money = Calculate(x, year);
//	cout << "您将得到的本息余额为：" << money;
//	return 0;
//}



//4.计算球的体积
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int r = 0;
//	cin >> r;
//	double V = (4.0 / 3) * 3.14 * pow(r, 3);
//	cout << V;
//	return 0;
//}


//5.反向输出数字
#include<iostream>
using namespace std;
void opponum(unsigned int i)
{
	if (i >= 10)
	{
		cout << i % 10;
		opponum(i / 10);
	}
	else
	{
		cout << i;
	}
}
int main()
{
	unsigned int i = 0;
	cin >> i;
	opponum(i);
	return 0;
}
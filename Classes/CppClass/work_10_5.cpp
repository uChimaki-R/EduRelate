//1.�����������ƽ��ֵ
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


//2.������������ֵ
//��1��������ʱ����
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
//	cout << "�����������ĺ󡪡�����\n";
//	cout << "a =" << a << endl;
//	cout << "b =" << b;
//	return 0;
//}


//��2�����ð�λ���
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
//	cout << "�����������ĺ󡪡�����\n";
//	cout << "a =" << a << endl;
//	cout << "b =" << b;
//	return 0;
//}



//3.���㱾Ϣ���
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
//	cout << "�����뱾����Ŀ��ת��������>\n";
//	cin >> x >> year;
//	float money = Calculate(x, year);
//	cout << "�����õ��ı�Ϣ���Ϊ��" << money;
//	return 0;
//}



//4.����������
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


//5.�����������
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
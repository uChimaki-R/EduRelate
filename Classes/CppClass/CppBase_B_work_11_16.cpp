////5_1.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int i = 0;
//	for (i = 200; i <= 300; i++)
//	{
//		int g = i % 10;
//		int s = i / 10 % 10;
//		int b = i / 100;
//		if ((g + s + b) == 12 && g * s * b == 42)
//		{
//			cout << i << endl;
//		}
//	}
//	return 0;
//}

////6.
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int i = 0;
//	for (i = 310000; i <= 319999; i++)
//	{
//		if ((i / 100 % 10) != (i / 1000 % 10) || (i % 10) != (i / 10 % 10))
//		{
//			continue;
//		}
//		if (pow(i%10000,0.5) == (int)pow(i%10000, 0.5))
//		{
//			cout << i << endl;
//		}
//	}
//	return 0;
//}

//7.
#include<iostream>
using namespace std;
int main()
{
	int my_count = 0;
	for (int a = 1; a <= 5; a++)
	{
		for (int b = 1; b <= 5; b++)
		{
			for (int c = 1; c <= 5; c++)
			{
				if (a != b && a != c && b != c)
				{
					if (my_count != 0 && my_count % 10 == 0)
					{
						cout << endl;
					}
					cout << a << b << c << '\t';
					my_count++;
				}
			}
		}
	}
	cout << endl << "count = " << my_count << endl;
	return 0;
}
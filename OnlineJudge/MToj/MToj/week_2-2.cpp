#include<iostream>
using namespace std;

int Xor[2010];

int main()
{
	int n,input;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		Xor[i] = Xor[i - 1] ^ input;
	}
	int max_xor = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			max_xor = max(max_xor, Xor[i] ^ Xor[j - 1]);
		}
	}
	cout << max_xor;
	return 0;
}



//#include<iostream>
//using namespace std;
//
//int input[2010];
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> input[i];
//	}
//	int max_xor = -1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			int this_xor = 0;
//			for (int k = j; k <= i; k++)
//			{
//				this_xor ^= input[k];
//			}
//			max_xor = max(max_xor, this_xor);
//		}
//	}
//	cout << max_xor;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//double Sin(double x, double error = 1e-6)
//{
//	double sin = 0;
//	double item = x;
//
//	for (int i = 2; fabs(item) > error; i++)
//	{
//		sin += item;
//		item = -item * x * x / (2 * i - 1) / (2 * i - 2);
//	}
//	return sin;
//}
//
//int main()
//{
//	double input, error;
//	cin >> input >> error;
//	double ret = Sin(input, error);
//	cout << "Sin(" << input << ") = " << ret << endl;
//	system("pause");
//	return 0;
//}
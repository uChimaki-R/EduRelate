////1.
//#include<iostream>
//using namespace std;
//int MaxY(int, int);
//int MinB(int, int);
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int max_y = MaxY(a, b);
//	int min_b = MinB(a, b);
//	cout << "最大公约数为:>" << max_y << endl << "最小公倍数为:>" << min_b << endl;
//	return 0;
//}
//int MaxY(int a, int b)
//{
//	int tmp = a % b;
//	if (tmp == 0)
//	{
//		return b;
//	}
//	else
//	{
//		return MaxY(b, tmp);
//	}
//}
//int MinB(int a, int b)
//{
//	int bigger = (a > b ? a : b);
//	int i = bigger;
//	while (1)
//	{
//		if (i % a == 0 && i % b == 0)
//		{
//			break;
//		}
//		i++;
//	}
//	return i;
//}

////2
//#include<iostream>
//#include<cmath>
//using namespace std;
//void Have2Sol(double, double, double);
//void Have1Sol(double, double);
//void NoSol();
//int main()
//{
//	double a, b, c;
//	cin >> a >> b >> c;
//	double delta = pow(b, 2) - 4.0 * a * c;
//	double ret = 0;
//	if (delta > 0)
//	{
//		Have2Sol(a, b, delta);
//	}
//	else if (delta == 0)
//	{
//		Have1Sol(a, b);
//	}
//	else if (delta < 0)
//	{
//		NoSol();
//	}
//	return 0;
//}
//void Have2Sol(double a, double b, double delta)
//{
//	double sol1 = (-b + pow(delta, 0.5)) / (2.0 * a);
//	double sol2 = (-b - pow(delta, 0.5)) / (2.0 * a);
//	cout << "sol1:>" << sol1 << endl;
//	cout << "sol2:>" << sol2 << endl;
//}
//void Have1Sol(double a, double b)
//{
//	double sol = -b / (2 * a);
//	cout << "sol:>" << sol << endl;
//}
//void NoSol()
//{
//	cout << "No solution." << endl;
//}

////3
//#include<iostream>
//#include<cmath>
//using namespace std;
//int isPrime(int);
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int i = isPrime(n);
//	if (i == 1)
//	{
//		cout << "YES" << endl;
//	}
//	else if (i == 0)
//	{
//		cout << "NO" << endl;
//	}
//	return 0;
//}
//int isPrime(int n)
//{
//	if (n == 1)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}

////4
//#include<iostream>
//using namespace std;
//unsigned int fac(unsigned int);
//int main()
//{
//	unsigned int a, b, c;
//	cin >> a >> b >> c;
//	unsigned int ret = fac(a) + fac(b) + fac(c);
//	cout << ret << endl;
//	return 0;
//}
//unsigned int fac(unsigned int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	return n * fac(n - 1);
//}


////5
//#include<iostream>
//#include<cmath>
//using namespace std;
//double my_sinh(double);
//int main()
//{
//	double x = 0;
//	cin >> x;
//	double ret = my_sinh(x);
//	cout << ret << endl;
//	return 0;
//}
//double ex(double x)
//{
//	return exp(x);
//}
//double my_sinh(double x)
//{
//	return (ex(x) - ex(-x)) / 2.0;
//}

////6
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	double a, b, c, d, x1, x2, i;
//	cout << "依次输入a，b，c，d:>";
//	cin >> a >> b >> c >> d;
//	cout << "输入一个实数，将在其附近求一个实根:>";
//	cin >> x1;
//	cout << "所需精度(如1e-6):>";
//	cin >> i;
//	x2 = x1 - (a * pow(x1, 3) + b * pow(x1, 2) + c * x1 + d) / (3 * a * pow(x1, 2) + 2 * b * x1 + c);
//	while (fabs(x2 - x1) > i)
//	{
//		x1 = x2;
//		x2 = x1 - (a * pow(x1, 3) + b * pow(x1, 2) + c * x1 + d) / (3 * a * pow(x1, 2) + 2 * b * x1 + c);
//	}
//	cout << x2;
//	return 0;
//}


////7
//#include<iostream>
//#include<cmath>
//using namespace std;
//int judge_p(int);
//void gotbaha(int);
//int main()
//{
//    int n = 0;
//    cin >> n;
//    while (n % 2 != 0 || n < 6)
//    {
//        cout << "You give an error num.Please try again:>" << endl;
//        cin >> n;
//    }
//    gotbaha(n);
//    return 0;
//}
//int judge_p(int n)
//{
//    int i = 0;
//    for (i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//void gotbaha(int n)
//{
//    int i = 2;
//    int j = 2;
//    for (i = 2; i < n; i++)
//    {
//        for (j = 2; j < n && j <= i; j++)
//        {
//            if (judge_p(j) == 1 && judge_p(i) == 1 && j + i == n)
//            {
//                cout << n << '=' << j << '+' << i << endl;
//            }
//        }
//    }
//}


////8
//#include<iostream>
//using namespace std;
//double p(int, double);
//int main()
//{
//	int n = 0;
//	double x = 0;
//	cin >> n >> x;
//	double ret = p(n, x);
//	cout << ret;
//	return 0;
//}
//double p(int n, double x)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (n == 1)
//	{
//		return x;
//	}
//	else if (n >= 1)
//	{
//		return ((2.0 * n - 1) * x - p(n - 1, x) - (n - 1.0) * p(n - 2, x)) / n;
//	}
//}


////9
//#include<iostream>
//using namespace std;
//int honota(int, char, char, char);
//int main()
//{
//	int n = 0;
//	cout << "盘子个数:>";
//	cin >> n;
//	int count1 = honota(n, 'a', 'b', 'c');
//	cout << endl << "count:>" << count1 <<endl;
//	return 0;
//}
//void move(char a, char c)
//{
//	static int change = 0;
//	if (change % 20 == 0 && change != 0)
//	{
//		cout << endl;
//	}
//	cout << a << "-->" << c << ' ';
//	change++;
//}
//int honota(int n, char a, char b, char c)
//{
//	static int count1 = 0;
//	if (n == 1)
//	{
//		move(a, c);
//		count1++;
//	}
//	else
//	{
//		honota(n - 1, a, c, b);
//		move(a, c);
//		count1++;
//		honota(n - 1, b, a, c);
//	}
//	return count1;
//}



////10
//#include<iostream>
//using namespace std;
//int main()
//{
//	char arr[1000];
//	cin.getline(arr, 1000);
//	cout << arr;
//	return 0;
//}


////11
//#include<iostream>
//using namespace std;
//unsigned int fx(unsigned int);
//int main()
//{
//	unsigned int n = 0;
//	cin >> n;
//	unsigned int ret = fx(n);
//	cout << ret;
//	return 0;
//}
//unsigned int fx(unsigned int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * n + fx(n - 1);
//	}
//}


////12
//#include<iostream>
//#include<cmath>
//using namespace std;
//double cul_s(double, double, double);
//double cul_area(double, double, double,double);
//int main()
//{
//	double a, b, c;
//	cin >> a >> b >> c;
//	double s = cul_s(a, b, c);
//	double area = cul_area(s, a, b, c);
//	cout << "s = " << s << endl;
//	cout << "area = " << area << endl;
//	return 0;
//}
//double cul_s(double a, double b, double c)
//{
//	return 0.5 * (a + b + c);
//}
//double cul_area(double s, double a, double b, double c)
//{
//	return pow(s * (s - a) * (s - b) * (s - c), 0.5);
//}
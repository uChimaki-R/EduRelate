////3.
//#include<iostream>
//using namespace std;
//int main()
//{
//	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = '\101', c5 = '\116';
//	cout << c1 << c2 << c3 << '\n';
//	cout<<"\t\b"<<c4<<'\t'<<c5<<'\n';
//	return 0;
//}

////4.
//#include<iostream>
//using namespace std;
//int main()
//{
//	char c1 = 'C', c2 = '+', c3 = '+';
//	cout << " I say : \"" << c1 << c2 << c3 << '\"';
//	cout << " \t\t" << " He says: \"C++ is very intersting!\"" << '\n';
//	return 0;
//}

////5
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	float r1 = 3.5 * 3 + 2 * 7 - 'a';
//	cout << r1 << endl;
//	float r2 = 26 / 3 + 34 % 3 + 2.5;
//	cout << r2 << endl;
//	int r3 = 45 / 2 + (int)3.14159 / 2;
//	cout << r3 << endl;
//	int a = 3;
//	int b, c;
//	int r4 = a = b = (c = a += 6);
//	cout << r4 << endl;
//	a = 3 * 5;
//	int r5 = a = b = 3 * 2;
//	cout << r5 << endl;
//    int r6 = (int)(a + 6.5) % 2 + (a = b = 5);
//	cout << r6 << endl;
//	float x = 2.5;
//	a = 7;
//	float y = 4.7;
//	float r7 = x + a % 3 * (int)(x + y) % 2 / 4;
//	cout << r7 << endl;
//	x = 3.5;
//	a = 2;
//	b = 3;
//	y = 2.5;
//	float r8 = (float)(a + b) / 2 + (int)x % (int)y;
//	cout << r8 << endl;
//	return 0;
//}

////6.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 12;
//	a += a;
//	cout << a << endl;
//	a = 12;
//	a -= 3;
//	cout << a << endl;
//	a = 12;
//	a *= 2 + 3;
//	cout << a << endl;
//	a = 12;
//	a /= a + a;
//	cout << a << endl;
//	a = 12;
//	int n = 5;
//	a %= (n %= 2);
//	cout << a << endl;
//	a = 12;
//	a += a -= a *= a;
//	cout << a << endl;
//
//	return 0;
//}

////7.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int i, j, m, n;
//	i = 8;
//	j = 10;
//	m = ++i + j++;
//	n = (++i) + (++j) + m;
//	cout << i << '\t' << j << '\t' << m << '\t' << n << endl;
//	return 0;
//}
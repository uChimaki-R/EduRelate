////5.
//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << " This" << " is";
//	cout << " a" << " C++";
//	cout << " program." << endl;
//	return 0;
//}

////6.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	a = 10;
//	b = 23;
//	c = a + b;
//	cout << " a + b = ";
//	cout << c;
//	cout << endl;
//	return 0;
//}

////7.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	int f(int x, int y, int z);
//	cin >> a >> b >> c;
//	c = f(a, b, c);
//	cout << c << endl;
//	return 0;
//}
//int f(int x, int y, int z)
//{
//	int m;
//	if (x < y)m = x;
//	else m = y;
//	if (z < m)m = z;
//	return(m);
//}

////8.
//// 原错误代码：
////int main();
////{
////	int a, b;
////	c = a + b;
////	cout >> " a + b = " >> a + b;
////}
////修改后：
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	cin >> a >> b;
//	c = a + b;
//	cout << " a + b = " << c << endl;
//	return 0;
//}

////9.
//////原错误代码：
////#include<iostream>
////using namespace std;
////int main()
////{
////	int a, b;
////	c = add(a, b)
////		cout << " a + b = " << c << endl;
////	return 0;
////}
////int add(int x,int y);
////{
////	z = x + y;
////	retrun(z);
////}
////修改后：
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	cin >> a >> b;
//	int add(int, int);
//	c = add(a, b);
//	cout << "a + b = " << c << endl;
//	return 0;
//}
//int add(int x, int y)
//{
//	int z;
//	z = x + y;
//	return(z);
//}

////10.
//#include<iostream>
//using namespace std;
//int main()
//{
//	void sort(int x, int y, int z);
//	int x, y, z;
//	cin >> x >> y >> z;
//	sort(x, y, z);
//	return 0;
//}
//void sort(int x, int y, int z)
//{
//	int temp;
//	if (x > y) { temp = x; x = y; y = temp;}
//	if (z < x) cout << z << ',' << x << ',' << y << endl;
//	else if (z < y) cout << x << ',' << z << ',' << y << endl;
//	else cout << x << ',' << y << ',' << z << endl;
//}
#include<iostream>
#include<algorithm>
using namespace std;

string tob(int val)
{
	string s = "";
	while (val) {
		s += '0' + val % 2;
		val /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	int t;
	cin >> t;
	while (--t) {
		int val;
		cin >> val;
		cout << tob(val) << endl;
	}
	return 0;
}
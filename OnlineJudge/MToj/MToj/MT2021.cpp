#include<iostream>
using namespace std;

typedef long long LL;

int main()
{
	LL n, m, s;
	cin >> n >> m >> s;
	cout << ((n - 1) / s + 1) * ((n - 1) % s + 1) * ((m - 1) / s + 1) * ((m - 1) % s + 1);
	return 0;
}
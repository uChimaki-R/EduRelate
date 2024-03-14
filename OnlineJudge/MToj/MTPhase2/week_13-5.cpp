#include<iostream>
using namespace std;

typedef long long LL;

const LL N = 100;
LL f[N];

int main()
{
	LL m, n;
	cin >> m >> n;
	f[1] = 1;
	f[2] = 2;
	for (LL i = 3; i <= m * (n - 1); i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[m * (n - 1)];
	return 0;
}
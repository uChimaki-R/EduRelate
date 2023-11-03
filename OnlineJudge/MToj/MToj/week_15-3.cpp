#include<iostream>
using namespace std;

typedef long long LL;
#define MOD 1000000007

const LL N = 100010;
LL f[N][2];

int main()
{
	f[1][0] = 0;
	f[1][1] = 3;
	for (int i = 2; i < N - 1; i++)
	{
		f[i][0] = f[i - 1][1];
		f[i][1] = 2 * (f[i - 1][0] + f[i - 1][1]) % MOD;
	}
	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		int val;
		cin >> val;
		cout << (f[val][0] + f[val][1]) % MOD << endl;
	}
	return 0;
}
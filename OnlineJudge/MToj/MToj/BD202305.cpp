#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll t, p, k;
	cin >> t;
	while (t--)
	{
		cin >> p >> k;
		if (k)cout << k - (k - 1) / p << endl;
		else cout << 0 << endl;
	}
	return 0;
}
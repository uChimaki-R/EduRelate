#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll cnt, val, ans = 0;
	cin >> cnt;
	while (cnt--)
	{
		cin >> val;
		ans += val;
	}
	cout << ans;
	return 0;
}
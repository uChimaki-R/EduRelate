#include<iostream>
#include<map>
using namespace std;

typedef long long LL;

const LL N = 200010;

map<LL, LL>mp;
LL arr[N];

int main()
{
	LL n, c, input;
	cin >> n >> c;
	for (LL i = 0; i < n; i++)
	{
		cin >> input;
		arr[i] = input;
		mp[input]++;
	}
	LL ans = 0;
	for (LL i = 0; i < n; i++)
	{
		ans += mp[c + arr[i]];
	}
	cout << ans;
	return 0;
}
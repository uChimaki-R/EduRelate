#include<iostream>
using namespace std;

const long long MOD = 1000000007;

int main()
{
	string s;
	cin >> s;
	long long ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		long long cnt = 0;
		while (i < s.length() && s[i] == '1')
		{
			cnt++;
			i++;
		}
		ans += cnt * (cnt + 1) / 2 % MOD;
	}
	cout << ans;
	return 0;
}
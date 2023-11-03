#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ans++;
			n /= i;
		}
	}
	if (n > 1)ans++;
	cout << ans;
	return 0;
}
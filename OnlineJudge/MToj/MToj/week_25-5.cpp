#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a == b)cout << "infinity";
	if (a < b)cout << 0;
	if (b < a) {
		int ans = 0;
		for (int i = 1; i * i <= (a - b); i++) {
			if ((a - b) % i == 0) {
				if (i > b)ans++;
				if (((a - b) / i > b) && (i * i != (a - b)))ans++;
			}
		}
		cout << ans;
	}
	return 0;
}
#include<iostream>
using namespace std;
#define int long long

int a[30] = { 0, 0, 1 };

signed main() {
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
	}
	cout << a[n];
	return 0;
}
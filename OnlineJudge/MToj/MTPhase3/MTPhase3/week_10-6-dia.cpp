#include<iostream>
using namespace std;
#define MOD 1000000;

int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b, a % b);
}

int main() {
	int n, m;
	cin >> n >> m;
	int t = gcd(n, m);
	if (t == 1)cout << 1;
	else {
		int f0 = 0, f1 = 1, f2 = 0;
		for (int i = 2; i <= t; i++) {
			f2 = f0 + f1;
			f2 %= MOD;
			f0 = f1;
			f1 = f2;
		}
		cout << f2;
	}
	return 0;
}
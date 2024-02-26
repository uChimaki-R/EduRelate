#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int N = 100007;
int n, a[3][N];
int tmp[N];

long long calc(int* a, int opt) {
	for (int i = 1; i <= n; i++) tmp[i] = a[i];
	sort(tmp + 1, tmp + 1 + n);
	if (opt) {
		for (int i = 1; i <= n; i++) tmp[i] -= i;
		sort(tmp + 1, tmp + 1 + n);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += abs(tmp[i] - tmp[n / 2 + 1]);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", a[0] + i, a[1] + i, a[2] + i);
	long long sum = 0, _min = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < 3; i++) {
		long long cur = calc(a[i], 0);
		_min = min(_min, calc(a[i], 1) - cur);
		sum += cur;
	}
	cout << sum + _min << endl;
}

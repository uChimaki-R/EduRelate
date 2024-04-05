#include<iostream>
using namespace std;

const int N = 5007;
int n, ans = 0;
int height[N];

void print(int l, int r) {
	int ph = 0x3f3f3f3f;
	for (int i = l; i <= r; i++) {
		ph = min(ph, height[i]);
	}
	int pw = r - l + 1;
	if (ph >= pw) {
		ans += pw;
	}
	else {
		for (int i = l; i <= r; i++) {
			height[i] -= ph;
		}
		ans += ph;
		while (l <= r) {
			while (l <= r && height[l] == 0)l++;
			int temp = l;
			while (temp <= r && height[temp])temp++;
			print(l, temp - 1);
			l = temp;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> height[i];
	print(1, n);
	cout << ans;
	return 0;
}
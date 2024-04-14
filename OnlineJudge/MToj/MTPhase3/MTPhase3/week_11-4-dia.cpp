#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100007;
int l, n, k;
int arr[N];

bool check(int len) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int dif = arr[i] - arr[i - 1];
		if (dif > len) {
			cnt += dif / len;
			if (!(dif % len))cnt -= 1;
		}
	}
	if (cnt <= k)return true;
	else return false;
}

int main() {
	cin >> l >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int le = 1, ri = l;
	int ans = 0;
	while (le <= ri) {
		int mi = le + (ri - le) / 2;
		if (check(mi)) {
			ans = mi;
			ri = mi - 1;
		}
		else le = mi + 1;
	}
	cout << ans;
	return 0;
}
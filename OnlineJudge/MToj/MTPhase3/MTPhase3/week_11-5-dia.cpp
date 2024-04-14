#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

const int N = 60;
int n, m;
int arr[N];

bool check(int len) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (len > arr[i]) {
			cnt += len - arr[i];
		}
	}
	if (cnt <= len && cnt <= m)return true;
	else return false;
}

signed main() {
	cin >> n >> m;
	int le = 0, ri = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ri = max(arr[i], ri);
	}
	ri += m;
	sort(arr, arr + n);
	int ans = 0;
	while (le <= ri) {
		int mi = le + (ri - le) / 2;
		if (check(mi)) {
			ans = mi;
			le = mi + 1;
		}
		else ri = mi - 1;
	}
	cout << ans;
	return 0;
}
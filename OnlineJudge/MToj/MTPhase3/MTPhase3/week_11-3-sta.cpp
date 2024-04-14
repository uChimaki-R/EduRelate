#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10007;
int t, k;
int arr[N], arr2[N][2];

bool check(int len) {
	int cnt = 1;
	int temp = 0;
	for (int i = 1; i <= t; i++) {
		if (temp + arr[i] > len) {
			cnt++;
			temp = arr[i];
		}
		else temp += arr[i];
	}
	if (cnt <= k)return true;
	else return false;
}

int main() {
	cin >> t >> k;
	int le = 0, ri = 0;
	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
		le = max(arr[i], le);
		ri += arr[i];
	}
	int ans = 0;
	while (le <= ri) {
		int mi = le + (ri - le) / 2;
		if (check(mi)) {
			ans = mi;
			ri = mi - 1;
		}
		else le = mi + 1;
	}
	int pos = k, temp = 0;
	for (int i = t; i > 0; i--) {
		if (!arr2[pos][1])arr2[pos][1] = i;
		if (temp + arr[i] > ans) {
			arr2[pos][0] = i + 1;
			pos--;
			temp = arr[i];
			arr2[pos][1] = i;
		}
		else temp += arr[i];
	}
	arr2[pos][0] = 1;
	for (int i = 1; i <= k; i++) {
		if (arr2[i][0] == 0) cout << 0 << " " << 0 << endl;
		else cout << arr2[i][0] << " " << arr2[i][1] << endl;
	}
	return 0;
}
#include<iostream>
using namespace std;

const int N = 100007;
int points[N];

bool check(int edges, int start, int len) {
	for (int p = start; --edges; p += len) {
		if (!points[p])return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> points[i];
	for (int i = 3; i <= n; i++) {
		if (n % i)continue;
		int len = n / i;
		// j为多边形的起点位置
		for (int j = 1; j <= len; j++) {
			if (check(i, j, len)) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
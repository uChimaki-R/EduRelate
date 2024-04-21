#include<iostream>
using namespace std;
#define int long long

const int N = 90;
string a0 = "IAKIOI";
string a1 = "WHENWILLSCORLLOFTAIWUCOMEOUT!!!";
int len[N];

char find(int n, int c) {
	if (n == 0)return a0[c - 1];
	else if (n == 1)return a1[c - 1];
	if (c <= len[n - 2])return find(n - 2, c);
	else return find(n - 1, c - len[n - 2]);
}

signed main() {
	int n, c;
	cin >> n >> c;
	len[0] = a0.length();
	len[1] = a1.length();
	for (int i = 2; i < N; i++) {
		len[i] = len[i - 1] + len[i - 2];
	}
	cout << find(n, c);
	return 0;
}
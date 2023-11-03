#include<iostream>
using namespace std;

int ans = 0, m, n;
void dfs(int flws, int cnts, int cntf) {
	if (flws == 0 && cnts == 0 && cntf == 0)ans++;
	if (flws <= 0 || cnts < 0 || cntf < 0)return;
	dfs(flws * 2, cnts - 1, cntf);
	dfs(flws - 2, cnts, cntf - 1);
}

int main() {
	cin >> m >> n;
	dfs(5, m, n);
	cout << ans;
	return 0;
}
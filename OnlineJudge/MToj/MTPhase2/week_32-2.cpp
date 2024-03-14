#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 10;
int n, ans = INF, tmp = 0;
int map[N][N], vis[N];

void dfs(int pos, int cnt) {
	if (cnt == n) {
		ans = min(ans, tmp + map[pos][1]);
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (!vis[i] && pos != i) {
				vis[i] = 1;
				tmp += map[pos][i];
				dfs(i, cnt + 1);
				vis[i] = 0;
				tmp -= map[pos][i];
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	dfs(1, 1);
	cout << ans;
	return 0;
}

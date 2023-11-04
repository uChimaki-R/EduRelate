#include<iostream>
using namespace std;

const int N = 120;
int map[N][N], len[N][N];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int n, m;

bool inMap(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

int dfs(int x, int y) {
	if (len[x][y])return len[x][y];
	len[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (inMap(nx, ny) && map[nx][ny] < map[x][y]) {
			len[x][y] = max(len[x][y], dfs(nx, ny) + 1);
		}
	}
	return len[x][y];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, dfs(i, j));
	cout << ans;
	return 0;
}
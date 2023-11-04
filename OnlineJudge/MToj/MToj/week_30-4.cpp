#include<iostream>
#include<queue>
using namespace std;

const int N = 15;
int vis[N][N][N];
char map[N][N][N];
int k, n, m, sx, sy, ans = 0;
int dir[6][3] = { 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1 };

struct Node {
	int x, y, z;
};

bool inMap(int x, int y, int z) {
	return x > 0 && x <= k && y > 0 && y <= n && z > 0 && z <= m;
}

void dfs() {
	queue<Node>qu;
	qu.push({ 1, sx, sy });
	while (!qu.empty()) {
		Node front = qu.front();
		qu.pop();
		ans++;
		vis[front.x][front.y][front.z] = true;
		for (int i = 0; i < 6; i++) {
			int nx = front.x + dir[i][0];
			int ny = front.y + dir[i][1];
			int nz = front.z + dir[i][2];
			if (inMap(nx, ny, nz) && !vis[nx][ny][nz] && map[nx][ny][nz] != '#') {
				vis[nx][ny][nz] = true;
				qu.push({ nx, ny, nz });
			}
		}
	}
}

int main() {
	cin >> k >> n >> m;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			for (int l = 1; l <= m; l++)
				cin >> map[i][j][l];
	cin >> sx >> sy;
	dfs();
	cout << ans;
	return 0;
}
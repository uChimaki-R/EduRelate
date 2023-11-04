#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

const int N = 2007;
int map[N][N], vis[N][N], ans[N][N];
int n, sx, sy;
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

void dfs() {
	queue<pii>qu;
	qu.push(make_pair(sx, sy));
	while (!qu.empty()) {
		pii front = qu.front();
		qu.pop();
		vis[front.first][front.second] = true;
		for (int i = 0; i < 4; i++) {
			int nx = (front.first + dir[i][0] + n) % n;
			int ny = (front.second + dir[i][1] + n) % n;
			if (map[nx][ny] && !vis[nx][ny]) {
				ans[nx][ny] = ans[front.first][front.second] + 1;
				vis[nx][ny] = true;
				qu.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
	dfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
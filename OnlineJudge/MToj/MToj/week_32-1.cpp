#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 107;
int n, m;
int map[N][N], val[N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> val[i];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = map[b - 1][a - 1] = 1;
	}
	int ans = INF;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (map[i][j] && map[i][k] && map[j][k])
					ans = min(ans, val[i] + val[j] + val[k]);
	if (ans == INF)cout << -1;
	else cout << ans;
	return 0;
}
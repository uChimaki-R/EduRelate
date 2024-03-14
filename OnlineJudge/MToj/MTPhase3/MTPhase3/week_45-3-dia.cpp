#include<iostream>
using namespace std;

const int N = 107;
char map[N][N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {
			for (int x2 = x1; x2 < n; x2++) {
				for (int y2 = y1; y2 < n; y2++) {
					int x3 = x2 - y2 + x1 + y1;
					int y3 = x2 + y2 - x1 + y1;
					int x4 = x2 + y2 + x1 - y1;
					int y4 = -x2 + y2 + x1 + y1;
					if (x3 & 1 | x4 & 1 | y3 & 1 | y4 & 1)continue;
					x3 /= 2, y3 /= 2, x4 /= 2, y4 /= 2;
					if (x3 < 0 || x3 >= n || x4 < 0 || x4 >= n || y3 < 0 || y3 >= n || y4 < 0 || y4 >= n)continue;
					int cnt = 0;
					if (map[x1][y1] == 'B' || map[x2][y2] == 'B' || map[x3][y3] == 'B' || map[x4][y4] == 'B')continue;
					if (map[x1][y1] == 'J')cnt++;
					if (map[x2][y2] == 'J')cnt++;
					if (map[x3][y3] == 'J')cnt++;
					if (map[x4][y4] == 'J')cnt++;
					if (cnt >= 3)ans = max(ans, (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
				}
			}
		}
	}
	cout << ans;
	return 0;
}
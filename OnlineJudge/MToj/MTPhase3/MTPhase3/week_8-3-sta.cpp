#include<iostream>
#include<string.h>
using namespace std;

const int N = 107;
int arr[N][N];
int temp[N][N];
int n, m, sum = 0;

bool check(int l, int w) {
	for (int i = 1; i <= n - l + 1; i++) {
		for (int j = 1; j <= m - w + 1; j++) {
			// 左上角的点
			int num = temp[i][j];
			// 对刻章内部的点都-num
			for (int k = 0; k < l; k++) {
				for (int p = 0; p < w; p++) {
					int ii = i + k, jj = j + p;
					temp[ii][jj] -= num;
					if (temp[ii][jj] < 0)return 0;
				}
			}
		}
	}
	// 检查是否全部为0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j])return 0;
		}
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	for (int l = n; l >= 1; l--) {
		for (int w = m; w >= 1; w--) {
			// 刻章大小
			if (sum % (l * w))continue;
			memcpy(temp, arr, sizeof(arr));
			if (check(l, w)) {
				cout << sum / (l * w);
				return 0;
			}
		}
	}
	return 0;
}
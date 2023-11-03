#include<iostream>
using namespace std;
#define int long long
#define MOD 0x1f1f1f1f

int matrix[11][11];

int det(int rc) {
	int flag = 1;
	for (int i = 1; i <= rc; i++)
		for (int j = i + 1; j <= rc; j++) {
			while (matrix[i][i]) {
				int di = matrix[j][i] / matrix[i][i];
				for (int k = i; k <= rc; k++)
					matrix[j][k] = (matrix[j][k] - matrix[i][k] * di % MOD + MOD) % MOD;
				swap(matrix[i], matrix[j]);
				flag = -flag;
			}
			swap(matrix[i], matrix[j]);
			flag = -flag;
		}
	int ret = 1;
	for (int i = 1; i <= rc; i++)ret *= matrix[i][i], ret = (ret + MOD) % MOD;
	ret *= flag;
	ret = (ret + MOD) % MOD;
	return ret;
}

signed main() {
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int rc;
		cin >> rc;
		for (int i = 1; i <= rc; i++)
			for (int j = 1; j <= rc; j++)
				cin >> matrix[i][j];
		cout << det(rc) << endl;
	}
}
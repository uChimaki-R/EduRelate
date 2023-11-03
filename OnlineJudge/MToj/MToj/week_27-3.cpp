#include <iostream>
#include <vector>

using namespace std;

// 矩阵乘法函数
vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int m = A.size(); // 矩阵A的行数
	int n = A[0].size(); // 矩阵A的列数
	int p = B[0].size(); // 矩阵B的列数

	vector<vector<int>> C(m, vector<int>(p, 0)); // 结果矩阵C

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return C;
}

vector<vector<int>>a, b;

int main() {
	int l, m, n;
	cin >> l >> m >> n;
	for (int i = 0; i < l; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			int val;
			cin >> val;
			row.push_back(val);
		}
		a.push_back(row);
	}
	for (int i = 0; i < m; i++) {
		vector<int>row;
		for (int j = 0; j < n; j++) {
			int val;
			cin >> val;
			row.push_back(val);
		}
		b.push_back(row);
	}
	vector<vector<int>> C = matrix_multiply(a, b);
	for (int i = 0; i < C.size(); i++) {
		cout << C[i][0];
		for (int j = 1; j < C[0].size(); j++) {
			cout << " " << C[i][j];
		}
		cout << endl;
	}
	return 0;
}

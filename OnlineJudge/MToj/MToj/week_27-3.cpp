#include <iostream>
#include <vector>

using namespace std;

// ����˷�����
vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int m = A.size(); // ����A������
	int n = A[0].size(); // ����A������
	int p = B[0].size(); // ����B������

	vector<vector<int>> C(m, vector<int>(p, 0)); // �������C

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

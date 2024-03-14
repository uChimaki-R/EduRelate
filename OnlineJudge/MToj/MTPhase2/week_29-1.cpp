#include<iostream>
using namespace std;

int n, m;
int arr[25];

void dfs(int p, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= p; i++)
			if (arr[i])
				cout << i << ' ';
		cout << endl;
	}
	for (int i = p + 1; i <= n; i++) {
		arr[i] = 1;
		dfs(i, cnt + 1);
		arr[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	return 0;
}
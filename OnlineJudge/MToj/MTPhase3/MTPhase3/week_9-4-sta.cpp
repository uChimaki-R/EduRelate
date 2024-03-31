#include<iostream>
using namespace std;

int n;
int num[5] = { 0, 2, 6, 10, 14 };
int sum[10][5];
string s = " spdf";

void fun(int x, int i, int j) {
	sum[i][j] = min(x, num[j]);
	int y = x - num[j];
	if (y <= 0)return;
	if (j == 1) {
		j = i / 2 + 1;
		i = (i + 1) / 2 + 1;
	}
	else {
		i++;
		j--;
	}
	fun(y, i, j);
}

int main() {
	cin >> n;
	fun(n, 1, 1);
	int i = 1;
	while (true) {
		for (int j = 1; j <= 4; j++) {
			if (!sum[i][1])return 0;
			if (sum[i][j])cout << i << s[j] << sum[i][j] << " ";
		}
		i++;
		cout << endl;
	}
	return 0;
}
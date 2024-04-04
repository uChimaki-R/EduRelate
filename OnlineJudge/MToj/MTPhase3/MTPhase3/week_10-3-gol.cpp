#include<iostream>
using namespace std;

int main() {
	int a, m;
	cin >> a >> m;
	for (int i = 0; i < 100000; i++) {
		a += a % m;
		if (a % m == 0) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}
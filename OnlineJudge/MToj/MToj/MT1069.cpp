#include<iostream>
using namespace std;

int s[100010];

int main() {
	s[1] = 2;
	for (int i = 2; i < 100010; i++) {
		s[i] = s[i - 1] + 2 * (i - 1);
	}
	int n;
	cin >> n;
	cout << s[n];
	return 0;
}

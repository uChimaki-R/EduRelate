#include<iostream>
using namespace std;

const int N = 10000007;
bool dislike[N];
int nex[N];

bool check(int i) {
	while (i) {
		if (i % 10 == 7)return true;
		i /= 10;
	}
	return false;
}

void init() {
	dislike[0] = true;
	int curr = 1;
	for (int i = 2; i <= N; i++) {
		if (check(i)) {
			int temp = i;
			while (temp <= N) {
				dislike[temp] = true;
				temp += i;
			}
		}
		if (!dislike[i]) {
			nex[curr] = i;
			curr = i;
		}
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while (t--) {
		int val;
		cin >> val;
		if (dislike[val])cout << -1 << endl;
		else cout << nex[val] << endl;
	}
	return 0;
}
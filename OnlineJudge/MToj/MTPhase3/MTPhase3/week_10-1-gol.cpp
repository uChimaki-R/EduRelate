#include<iostream>
#include<deque>
using namespace std;

int n, m, k, t;
const int N = 60;
deque<int>qu;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> t;
		qu.push_back(t);
	}
	cin >> k;
	k %= (m * n);
	while (k--) {
		t = qu.back();
		qu.pop_back();
		qu.push_front(t);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << qu.front() << " ";
			qu.pop_front();
		}
		cout << endl;
	}
	return 0;
}
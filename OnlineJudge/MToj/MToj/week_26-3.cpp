#include<iostream>
#include<vector>
using namespace std;

const int N = 10000100;
bool have_frt[N];
vector<int>ans;

int getNext(int i) {
	int next = i;
	while (i) {
		next += i % 10;
		i /= 10;
	}
	return next;
}

void init() {
	for (int i = 1; i <= N; i++) {
		int next = getNext(i);
		if (next < N)have_frt[next] = true;
		if (!have_frt[i])ans.push_back(i);
	}
}

int main() {
	init();
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!have_frt[i]) cnt++;
	}
	cout << cnt << endl;
	for (int i = 0; i < k; i++) {
		int pos;
		cin >> pos;
		cout << ans[pos - 1] << ' ';
	}
	return 0;
}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1007;

int n, ans = 0;
vector<queue<int>>players;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		queue<int>qu;
		int t;
		for (int j = 1; j < n; j++) {
			cin >> t;
			qu.push(t);
		}
		players.push_back(qu);
	}
	while (true) {
		bool goon = false;
		bool vis[N] = { false };
		for (int i = 0; i < players.size(); i++) {
			if (vis[i + 1] || players[i].empty())continue;
			int front = players[i].front();
			if (vis[front] || players[front - 1].empty() || players[front - 1].front() != i + 1)continue;
			goon = true;
			vis[i + 1] = vis[front] = true;
			players[i].pop();
			players[front - 1].pop();
		}
		if (!goon)break;
		ans++;
	}
	bool legal = true;
	for (int i = 0; i < players.size(); i++) {
		if (!players[i].empty())legal = false;
	}
	if (!legal)cout << -1;
	else cout << ans;
	return 0;
}
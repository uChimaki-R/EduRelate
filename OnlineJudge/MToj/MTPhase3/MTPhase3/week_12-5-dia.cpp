#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100007;
string words[N], s;
vector<int> w[30];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> words[i];
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		w[s[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int p = -1;
		bool flag = true;
		for (int j = 0; j < words[i].length(); j++) {
			auto it = lower_bound(w[words[i][j] - 'a'].begin(), w[words[i][j] - 'a'].end(), p);
			if (it == w[words[i][j] - 'a'].end()) {
				flag = false;
				break;
			}
			p = w[words[i][j] - 'a'][distance(w[words[i][j] - 'a'].begin(), it)];
		}
		if (flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
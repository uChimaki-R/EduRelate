#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<ll>v;

void dfs(ll pos) {
	v.push_back(pos);
	for (ll i = pos % 16 + 1; i < 16; i++) {
		dfs(pos * 16 + i);
	}
}

int main() {
	dfs(0);
	sort(v.begin(), v.end());
	ll flag = 1;
	if (cin.peek() == '-') {
		cin.get();
		flag = -1;
	}
	while (cin.peek() == '0')cin.get();
	ll last = 0, ans = 0;
	char c;
	while ((c = cin.get()) != '\n') {
		ll val;
		if ('0' <= c && c <= '9')val = c - '0';
		else val = c - 'A' + 10;
		if (val <= last) {
			cout << "error";
			return 0;
		}
		ans = ans * 16 + val;
		last = val;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == ans) {
			cout << i * flag;
			break;
		}
	}
	return 0;
}
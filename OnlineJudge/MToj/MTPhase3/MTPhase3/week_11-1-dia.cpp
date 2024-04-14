#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<string, int>mp1;
map<int, string>mp2;
int n, m, t, a, b;
string s1, s2;

int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		cin >> s1;
		mp1[s1] = i;
		mp2[i] = s1;
	}
	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		s1 = mp2[a];
		s2 = mp2[b];
		mp2[a] = s2;
		mp2[b] = s1;
		mp1[s1] = b;
		mp1[s2] = a;
	}
	for (int i = 1; i <= m; i++) {
		cin >> s1;
		cout << mp1[s1] << endl;
	}
	return 0;
}
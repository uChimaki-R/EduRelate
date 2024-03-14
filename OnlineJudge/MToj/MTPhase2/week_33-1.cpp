#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int ans = 0, l, r, temp;
	for (int i = 0; i < s.length(); i++) {
		l = i - 1;
		r = i + 1;
		temp = 1;
		while (l >= 0 && r < s.length() && s[l] == s[r]) {
			temp += 2;
			l--, r++;
		}
		ans = max(ans, temp);
		l = i;
		r = i + 1;
		temp = 0;
		while (l >= 0 && r < s.length() && s[l] == s[r]) {
			temp += 2;
			l--, r++;
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}

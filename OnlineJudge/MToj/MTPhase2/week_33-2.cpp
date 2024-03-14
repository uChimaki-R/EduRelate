#include<iostream>
using namespace std;

int judge(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
	return 0;
}

int main() {
	string s;
	cin >> s;
	int k, ans = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
		if (judge(s[i]))ans++;
	int l = 0, r = k - 1, tmp = ans;
	while (r < s.length()) {
		if (!judge(s[l]) && judge(s[r + 1]))tmp++;
		if (judge(s[l]) && !judge(s[r + 1]))tmp--;
		ans = max(ans, tmp);
		l++, r++;
	}
	cout << ans;
	return 0;
}
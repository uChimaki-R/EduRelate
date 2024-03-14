#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int n, m;
string val;
stack<int>num;
vector<int>ans;

int main()
{
	cin >> n >> m >> val;
	for (int i = 0; i < n; i++)num.push(val[i] - '0');
	cin >> val;
	for (int i = 0; i < m; i++) {
		switch (val[i]) {
		case '+':
			if (num.top()) {
				int cnt = 0;
				while (num.top()) {
					num.pop();
					cnt++;
				}
				num.pop();
				num.push(1);
				while (cnt--) {
					num.push(0);
				}
			}
			else {
				num.pop();
				num.push(1);
			}
			break;
		case '-':
			if (num.top()) {
				num.pop();
				num.push(0);
			}
			else {
				int cnt = 0;
				while (!num.top()) {
					num.pop();
					cnt++;
				}
				num.pop();
				num.push(0);
				while (cnt--) {
					num.push(1);
				}
			}
			break;
		case '*':
			num.push(0);
			break;
		case '/':
			num.pop();
			break;
		}
	}
	while (!num.empty()) {
		ans.push_back(num.top());
		num.pop();
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
	return 0;
}
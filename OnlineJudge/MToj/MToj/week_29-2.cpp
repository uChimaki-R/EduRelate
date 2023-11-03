#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

vector<int>nums;

void dfs(int num, int cnt4, int cnt7) {
	if (num > 1000000000000)return;
	if (num && cnt4 == cnt7)nums.push_back(num);
	dfs(num * 10 + 4, cnt4 + 1, cnt7);
	dfs(num * 10 + 7, cnt4, cnt7 + 1);
}

signed main() {
	dfs(0, 0, 0);
	sort(nums.begin(), nums.end());
	int input;
	cin >> input;
	for (auto i : nums)
		if (i >= input) {
			cout << i;
			break;
		}
	return 0;
}
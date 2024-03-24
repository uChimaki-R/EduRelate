#include<iostream>
#include<stack>
#include<vector>
using namespace std;

const int N = 200007;

int books[N];
stack<int>st;
vector<int>ans;

int main() {
	int n, c;
	cin >> n >> c;
	for (int i = n; i >= 1; i--)cin >> books[i];
	books[0] = n;
	while (true) {
		if (books[0] == 0) {
			while (!st.empty()) {
				ans.push_back(st.top());
				st.pop();
			}
			break;
		}
		int st_size = c - st.size();
		int cmp_cnt = min(books[0], st_size);
		int min_num = N;
		int st_top = N;
		if (!st.empty())st_top = st.top();
		for (int i = books[0]; cmp_cnt--; i--) {
			if (books[i] < min_num) {
				min_num = books[i];
			}
		}
		if (min_num < st_top) {
			for (int i = books[0]; ; i--) {
				st.push(books[i]);
				books[0]--;
				if (books[i] == min_num)break;
			}
		}
		ans.push_back(st.top());
		st.pop();
	}
	for (auto i : ans) {
		cout << i << " ";
	}
	return 0;
}
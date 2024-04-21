#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

const int N = 100007;
int arr1[N], arr2[N];
int n;
deque<int>dq1, dq2;

int mscore(deque<int> d1, deque<int> d2) {
	int score = 0;
	while (!d1.empty() && !d2.empty()) {
		if (d1.front() > d2.front()) {
			score += 2;
			d1.pop_front();
			d2.pop_front();
		}
		else if (d1.back() > d2.back()) {
			score += 2;
			d1.pop_back();
			d2.pop_back();
		}
		else {
			score += d1.front() == d2.back();
			d1.pop_front();
			d2.pop_back();
		}
	}
	return score;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr1[i];
	for (int i = 0; i < n; i++) cin >> arr2[i];
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	for (int i = 0; i < n; i++)dq1.push_back(arr1[i]);
	for (int i = 0; i < n; i++)dq2.push_back(arr2[i]);
	cout << mscore(dq1, dq2) << " " << 2 * n - mscore(dq2, dq1);
	return 0;
}
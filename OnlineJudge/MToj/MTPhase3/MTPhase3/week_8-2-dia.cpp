#include<iostream>
using namespace std;

const int N = 1000007;
int arr[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = arr[0];
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] > arr[i])ans += arr[i + 1] - arr[i];
	}
	cout << ans;
	return 0;
}
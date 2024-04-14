#include<iostream>
#include<iomanip>
using namespace std;

const int N = 1007;
float arr1[N], arr2[N];

int main() {
	int n, m, x, y;
	float z;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
	}
	float ans = 0;
	while (m--) {
		cin >> x >> y >> z;
		if (arr1[x] < z) {
			cout << fixed << setprecision(2) << ans;
			return 0;
		}
		arr1[x] -= z;
		arr1[y] += int(z);
		float cnt = z - int(z);
		ans += cnt;
		arr2[y] += cnt;
		if (arr2[y] > 1) {
			cout << fixed << setprecision(2) << ans;
			return 0;
		}
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}
#include<iostream>
using namespace std;

const int N = 1000007;
int addn[N], arr[N];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	while (m--) {
		int opr;
		cin >> opr;
		if (opr == 1) {
			int x, y;
			cin >> x >> y;
			addn[x] += y;
		}
		else {
			int p;
			cin >> p;
			int ans = arr[p];
			for (int i = 1; i <= p / i; i++) {  // sqrt
				if (p % i == 0) {
					if (i * i == p) {
						ans += addn[i];
					}
					else {
						ans += (addn[i] + addn[p / i]);
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
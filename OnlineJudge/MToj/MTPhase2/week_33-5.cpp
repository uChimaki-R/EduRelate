#include<iostream>
using namespace std;

int main() {
	int l = 1, r = 2, x, sum = 0, flag = 0;
	cin >> x;
	while (l <= x / 2) {
		sum = (l + r) * (r - l + 1) / 2;
		if (sum == x) {
			flag = 1;
			cout << l << " " << r << endl;
			l++, r++;
		}
		else if (sum > x) l++;
		else r++;
	}
	if (!flag)cout << "No" << endl;
	return 0;
}

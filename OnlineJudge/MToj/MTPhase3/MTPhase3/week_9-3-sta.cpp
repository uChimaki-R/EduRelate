#include<iostream>
using namespace std;

int n, a, b, c;

bool check(int w, int h) {
	if (w >= 3 * a + b + c && h >= b + c)return true;
	if (w >= 2 * a + 2 * b && h >= 2 * a + c)return true;
	if (w >= 2 * a + 2 * b && h >= a + b + c)return true;
	if (w >= a + b + 2 * c && h >= a + b + c)return true;
	return false;
}

int main() {
	cin >> n >> a >> b >> c;
	int ans = 0;
	while (n--) {
		int w, h;
		cin >> w >> h;
		if (check(w, h)) { ans++; continue; }
		if (check(h, w)) { ans++; continue; }
		swap(a, b);
		if (check(w, h)) { ans++; continue; }
		if (check(h, w)) { ans++; continue; }
		swap(b, c);
		if (check(w, h)) { ans++; continue; }
		if (check(h, w)) { ans++; continue; }
		swap(a, c);
		if (check(w, h)) { ans++; continue; }
		if (check(h, w)) { ans++; continue; }
		swap(a, b);
		if (check(w, h)) { ans++; continue; }
		if (check(h, w)) { ans++; continue; }
		swap(b, c);
		if (check(w, h)) { ans++; continue; }
		if (check(h, w)) { ans++; continue; }
	}
	cout << ans << endl;
	return 0;
}
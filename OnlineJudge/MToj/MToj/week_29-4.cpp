#include<stdio.h>
#include<string.h>
using namespace std;

int n, k, a[25][25], b[25];
int check(int x) {
	for (int i = 0; i < 1 << n; i += 2) {
		memset(b, 0, sizeof(b));
		int now = __builtin_popcount(i);
		for (int j = 0; j < n; j++) {
		here:;
			if (now > k)break;
			for (int k = 0, p = 0; k < n; k++) {
				if ((i >> k) & 1)p++;
				if ((b[p] += a[j][k]) > x) {
					memset(b, 0, sizeof(b));
					now++;
					goto here;
				}
			}
		}
		if (now <= k)return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	int L = 0, R = 1e6, ans = 1e6;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid))ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	printf("%d\n", ans);
}
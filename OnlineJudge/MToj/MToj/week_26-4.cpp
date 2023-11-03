#include<iostream>
#include<iomanip>
using namespace std;

const int N = 100000007;
bool check[N];
int prime[N];

int getPcnt(int n) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (!check[i])prime[cnt++] = i;
		for (int j = 0; prime[j] * i <= n; j++) {
			check[prime[j] * i] = true;
			if (i % prime[j] == 0)break;
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	int pcnt = getPcnt(n);
	cout << fixed << setprecision(3) << double(pcnt) / n;
	return 0;
}
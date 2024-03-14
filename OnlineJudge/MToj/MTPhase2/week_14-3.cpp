#include<iostream>
#include<string.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef long long LL;
const LL N = 60;
string s;
LL f[110][N][2];

int main()
{
	cin >> s;
	s = ' ' + s;
	LL n;
	cin >> n;
	memset(f, -INF, sizeof(f));
	f[0][0][0] = f[0][0][1] = 0;
	for (LL i = 1; i < s.length(); i++)
	{
		for (LL j = 0; j <= n; j++)
		{
			for (LL l = 0; l <= j; l++)
			{
				if ((s[i] == 'T' && l % 2) || (s[i] == 'F' && !l % 2))
				{
					f[i][j][0] = max(f[i][j][0], f[i - 1][j - l][0] + 1);
					f[i][j][1] = max(f[i][j][1], f[i - 1][j - l][1] - 1);
				}
				else
				{
					f[i][j][0] = max(f[i][j][0], f[i - 1][j - l][1]);
					f[i][j][1] = max(f[i][j][1], f[i - 1][j - l][0]);
				}
			}
		}
	}
	cout << max(f[s.length() - 1][n][0], f[s.length() - 1][n][1]);
	return 0;
}
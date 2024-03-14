#include<iostream>
using namespace std;

typedef long long LL;

const LL N = 100010;

LL a[N], f[4 * N], v[4 * N];

void buildtree(LL k, LL l, LL r)
{
	v[k] = 0;
	if (l == r)
	{
		f[k] = a[l];
		return;
	}
	LL m = (l + r) >> 1;
	buildtree(k << 1, l, m);
	buildtree(k << 1 | 1, m + 1, r);
	f[k] = f[k << 1] + f[k << 1 | 1];
}

void add(LL k, LL l, LL r, LL x, LL y, LL z)
{
	if (l == x && r == y)
	{
		v[k] += z;
		return;
	}
	if (v[k])
	{
		v[k << 1] += v[k];
		v[k << 1 | 1] += v[k];
		v[k] = 0;
	}
	LL m = (l + r) >> 1;
	if (y <= m)
	{
		add(k << 1, l, m, x, y, z);
	}
	else if (x > m)
	{
		add(k << 1 | 1, m + 1, r, x, y, z);
	}
	else
	{
		add(k << 1, l, m, x, m, z);
		add(k << 1 | 1, m + 1, r, m + 1, y, z);
	}
	f[k] = f[k << 1] + v[k << 1] * (m - l + 1) + f[k << 1 | 1] + v[k << 1 | 1] * (r - m);
}

LL calc(LL k, LL l, LL r, LL x, LL y)
{
	if (l == x && r == y)
	{
		return f[k] + v[k] * (r - l + 1);
	}
	if (v[k])
	{
		v[k << 1] += v[k];
		v[k << 1 | 1] += v[k];
		v[k] = 0;
	}
	LL m = (l + r) >> 1;
	LL res = 0;
	if (y <= m)
	{
		res = calc(k << 1, l, m, x, y);
	}
	else if (x > m)
	{
		res = calc(k << 1 | 1, m + 1, r, x, y);
	}
	else
	{
		res = calc(k << 1, l, m, x, m) + calc(k << 1 | 1, m + 1, r, m + 1, y);
	}
	f[k] = f[k << 1] + v[k << 1] * (m - l + 1) + f[k << 1 | 1] + v[k << 1 | 1] * (r - m);
	return res;
}

int main()
{
	LL n, m;
	cin >> n >> m;
	for (LL i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	buildtree(1, 1, n);
	while (m--)
	{
		LL opr, x, y, k;
		cin >> opr;
		if (opr == 1)
		{
			cin >> x >> y >> k;
			add(1, 1, n, x, y, k);
		}
		else
		{
			cin >> x >> y;
			cout << calc(1, 1, n, x, y) << endl;
		}
	}
	return 0;
}
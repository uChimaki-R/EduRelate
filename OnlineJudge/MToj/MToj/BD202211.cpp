#include<iostream>
#include<vector>
using namespace std;
#define int long long
#define pii pair<int, int>
#define MOD 998244353

const int N = 1e6 + 7;
int n, t[N];

struct Tree
{
	//val是作为父亲节点时自己的权值
	int val = 0, sum = 0;
	vector<pii>sons;//pii第一个参数是儿子编号，第二个参数是到儿子的权值
}tr[N];

int ksm(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

int ddiv(int a, int b)
{
	return a % MOD * ksm(b, MOD - 2) % MOD;
}

void dfs(int pos)
{
	int sum = 0;
	for (auto i : tr[pos].sons)
	{
		dfs(i.first);
		sum = (sum + t[i.first] * i.second % MOD) % MOD;
	}
	t[pos] = ddiv((sum + tr[pos].sum), tr[pos].sum - tr[pos].val);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> tr[i].val;
	for (int i = 2; i <= n; i++)
	{
		int p, val;
		cin >> p >> val;
		tr[p].sons.push_back(make_pair(i, val));
		tr[p].sum += val;
	}
	for (int i = 1; i <= n; i++)tr[i].sum += tr[i].val;
	dfs(1);
	cout << t[1];
	return 0;
}
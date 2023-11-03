#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;

int n, m, ans;

struct Card
{
	int val, cnt;
	bool operator<(const Card& ca) const
	{
		return val < ca.val;
	}
}cards[N];

void dfs(int pos, int sum)
{
	if (sum == n)
	{
		ans++;
		return;
	}
	if (sum > n)
	{
		return;
	}
	for (int i = pos; i < m; i++)
	{
		for (int j = 1; j <= cards[i].cnt; j++)
		{
			cards[i].cnt -= j;
			dfs(i + 1, sum + j * cards[i].val);
			cards[i].cnt += j;
		}
	}
}

int main()
{
	int flag = 0;
	while (cin >> n >> m)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> cards[i].val >> cards[i].cnt;
		}
		sort(cards, cards + m);
		ans = 0;
		dfs(0, 0);
		if (flag)
		{
			cout << endl;
		}
		cout << ans << endl;
		flag = 1;
	}
	return 0;
}
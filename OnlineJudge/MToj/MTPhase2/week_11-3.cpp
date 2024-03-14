#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;

const LL N = 10000010;
LL head, tail, pos, n, m;
LL c1[N], e1[N], c2[N], e2[N];

struct Node
{
	LL next, coef, expn;
}nodes[N];

void insert(LL cur, LL coef, LL expn)
{
	pos++;
	nodes[pos].coef = coef;
	nodes[pos].expn = expn;
	nodes[pos].next = nodes[cur].next;
	nodes[cur].next = pos;
	if (!nodes[pos].next)
	{
		tail = pos;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld", &c1[i], &e1[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld %lld", &c2[i], &e2[i]);
	}
	LL l1 = 1, l2 = 1;
	while (l1 <= n && l2 <= m)
	{
		if (e1[l1] == e2[l2])
		{
			insert(tail, c1[l1] + c2[l2], e2[l2]);
			l1++;
			l2++;
		}
		else if (e1[l1] < e2[l2])
		{
			insert(tail, c1[l1], e1[l1]);
			l1++;
		}
		else
		{
			insert(tail, c2[l2], e2[l2]);
			l2++;
		}
	}
	while (l1 <= n)
	{
		insert(tail, c1[l1], e1[l1]);
		l1++;
	}
	while (l2 <= m)
	{
		insert(tail, c2[l2], e2[l2]);
		l2++;
	}
	for (int i = nodes[head].next; i != 0; i = nodes[i].next)
	{
		if (nodes[i].coef)
		{
			printf("%lld %lld\n", nodes[i].coef, nodes[i].expn);
		}
	}
	return 0;
}


//#include<iostream>
//#include<map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//typedef pair<int, int> pii;
//
//const int N = 1000000000;
//map<int, int>mp1, mp2;
//vector<pii>v;
//
//bool mycmp(const pii& p1, const pii& p2)
//{
//	return p1.second < p2.second;
//}
//
//int main()
//{
//	int n, m, a, b;
//	cin >> n >> m;
//	while (n--)
//	{
//		cin >> a >> b;
//		mp1[b + N] = a;
//	}
//	while (m--)
//	{
//		cin >> a >> b;
//		mp2[b + N] = a;
//	}
//	if (mp1.size() < mp2.size())
//	{
//		mp1.swap(mp2);
//	}
//	for (auto it = mp1.begin(); it != mp1.end(); it++)
//	{
//		int a = it->second + mp2[it->first];
//		if (a)
//		{
//			v.push_back(make_pair(a, it->first - N));
//		}
//	}
//	for (auto it = mp2.begin(); it != mp2.end(); it++)
//	{
//		if (!mp1.count(it->first))
//		{
//			v.push_back(make_pair(it->second, it->first - N));
//		}
//	}
//	sort(v.begin(), v.end(), mycmp);
//	for (auto it = v.begin(); it != v.end(); it++)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//	return 0;
//}
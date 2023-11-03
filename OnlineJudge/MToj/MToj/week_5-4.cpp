#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int, int>mp;

bool mycmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.first > p2.first;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		mp[input]++;
	}
	vector<pair<int, int>>v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), mycmp);
	int cnt = 0, pos = 0;
	while (cnt < k && v[pos].first != 0)
	{
		cnt += v[pos++].second;
	}
	cout << cnt;
	return 0;
}
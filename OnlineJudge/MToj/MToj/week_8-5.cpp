#include<iostream>
#include<queue>
using namespace std;

typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>>heap;

int main()
{
	LL n, val, ans = 0;
	cin >> n;
	while (n--)
	{
		cin >> val;
		heap.push(val);
	}
	while (heap.size() != 1)
	{
		LL v1 = heap.top();
		heap.pop();
		LL v2 = heap.top();
		heap.pop();
		heap.push(v1 + v2);
		ans += (v1 + v2);
	}
	cout << ans;
	return 0;
}
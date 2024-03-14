#include<iostream>
#include<queue>
using namespace std;

//相同数太多，使用结构体将相同数合并为一个变量

typedef long long LL;

struct Same
{
	LL val, cnt;
	bool operator>(const Same& s)const
	{
		return this->val > s.val;
	}
};

int main()
{
	LL n;
	cin >> n;
	while (n--)
	{
		LL cnt, ans = 0;
		cin >> cnt;
		priority_queue<Same, vector<Same>, greater<Same>>heap;
		heap.push({ 1,cnt });
		while (!(heap.size() == 1 && heap.top().cnt == 1))
		{
			Same top = heap.top();
			heap.pop();
			if (top.cnt % 2)
			{
				if (top.cnt > 1)
				{
					heap.push({ top.val * 2,top.cnt / 2 });
				}
				Same next = heap.top();
				heap.pop();
				heap.push({ top.val + next.val,1 });
				ans += next.val - top.val;
				if (next.cnt > 1)
				{
					heap.push({ next.val,next.cnt - 1 });
				}
			}
			else
			{
				heap.push({ top.val * 2,top.cnt / 2 });
			}
		}
		cout << ans << endl;
	}
	return 0;
}

//暴力法，超时超空间

//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int cnt, ans = 0;
//		cin >> cnt;
//		priority_queue<char, vector<char>, greater<char>>heap;
//		while (cnt--)
//		{
//			heap.push(1);
//		}
//		while (heap.size() != 1)
//		{
//			char a = heap.top();
//			heap.pop();
//			char b = heap.top();
//			heap.pop();
//			ans += abs(a - b);
//			heap.push(a + b);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}
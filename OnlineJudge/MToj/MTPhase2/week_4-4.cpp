#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class p
{
public:
	p(long long _a, long long _b)
	{
		a = _a;
		b = _b;
	}
	long long a, b;
};

vector<p>v;

bool mysort(p p1, p p2)
{
	if (p1.a == p2.a)
	{
		return p1.b >= p2.b;
	}
	return p1.a > p2.a;
}

int main()
{
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a >> b;
		v.push_back(p(a, b));
	}
	sort(v.begin(), v.end(), mysort);
	long long last = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].a != last)
		{
			last = v[i].a;
			continue;
		}
		sum += v[i].b;
		last = v[i].a;
	}
	cout << sum;
	return 0;
}
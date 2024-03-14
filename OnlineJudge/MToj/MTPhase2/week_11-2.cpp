#include<iostream>
using namespace std;

const int N = 20010;

int f[N];

int find(int i)
{
	if (f[i] == i)
	{
		return i;
	}
	return f[i] = find(f[i]);
}

void merge(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (fa != fb)
	{
		f[fb] = fa;
	}
}

int main()
{
	int n, q, a, b;
	for (int i = 1; i <= 20000; i++)
	{
		f[i] = i;
	}
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		merge(a, b);
	}
	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		cout << (int)(find(a) == find(b)) << endl;
	}
	return 0;
}
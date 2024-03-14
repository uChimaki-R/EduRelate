#include<iostream>
using namespace std;

const int N = 1e6 + 7;

int st[N];
int minst[N];

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int opr;
		cin >> opr;
		switch (opr)
		{
		case 1:
			int input;
			cin >> input;
			if (!minst[0] || minst[*minst] >= input)
			{
				minst[++ * minst] = input;
			}
			st[++ * st] = input;
			break;
		case 2:
			if (minst[*minst] == st[*st])
			{
				--* minst;
			}
			--* st;
			break;
		case 3:
			cout << st[*st] << endl;
			break;
		case 4:
			cout << minst[*minst] << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
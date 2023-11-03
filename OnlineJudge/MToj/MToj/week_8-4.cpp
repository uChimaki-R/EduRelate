#include<iostream>
#include<deque>
using namespace std;

deque<int>dq;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int opr, val;
		cin >> opr;
		switch (opr)
		{
		case 1:
			cin >> val;
			dq.push_front(val);
			break;
		case 2:
			cin >> val;
			dq.push_back(val);
			break;
		case 3:
			cout << dq.front() << endl;
			break;
		case 4:
			cout << dq.back() << endl;
			break;
		case 5:
			dq.pop_front();
			break;
		case 6:
			dq.pop_back();
			break;
		default:
			break;
		}
	}
	return 0;
}
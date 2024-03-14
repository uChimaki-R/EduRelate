#include<iostream>
using namespace std;

int arr[100005];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		arr[i] = arr[i - 1] + input;
	}
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		cout << arr[y] - arr[x - 1] << endl;
	}
	return 0;
}
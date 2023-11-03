#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int arr[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[i] -= input;
	}
	int left = 0;
	int right = n - 1;
	sort(arr, arr + n);
	while (left < right)
	{
		if (arr[left] + arr[right])
		{
			cout << "NO";
			return 0;
		}
		left++;
		right--;
	}
	cout << "YES";
	return 0;
}
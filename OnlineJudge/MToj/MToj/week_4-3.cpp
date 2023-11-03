#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int N;
long long ans = 0;
int arr[505];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long last = 0;
	for (int i = 0; i < N - 1; i++)
	{
		ans += (last + arr[i]);
		last += arr[i];
	}
	cout << fixed << setprecision(2) << (double)ans / (double)N;
	return 0;
}
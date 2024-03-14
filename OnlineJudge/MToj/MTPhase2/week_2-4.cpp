#include <iostream>
using namespace std;

// 使用差分解决
int matrix[1010][1010];
int sub[1010][1010];

void insert_sub(int r1, int c1, int r2, int c2, int val)
{
	sub[r1][c1] += val;
	sub[r1][c2 + 1] -= val;
	sub[r2 + 1][c1] -= val;
	sub[r2 + 1][c2 + 1] += val;
}

int main()
{
	int n, num;
	cin >> n >> num;
	for (int i = 0; i < num; i++)
	{
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		insert_sub(r1, c1, r2, c2, 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			matrix[i][j] = sub[i][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + matrix[i - 1][j];
			if (j != 1)
			{
				cout << " ";
			}
			cout << matrix[i][j];
		}
		if (i != n)
		{
			cout << endl;
		}
	}
	return 0;
}


// #include<iostream>
// using namespace std;

// int matrix[1010][1010];

// int main()
// {
// 	int n, num;
// 	cin >> n >> num;
// 	for (int i = 0; i < num; i++)
// 	{
// 		int r1, r2, c1, c2;
// 		cin >> r1 >> c1 >> r2 >> c2;
// 		for (int i = r1; i <= r2; i++)
// 		{
// 			for (int j = c1; j <= c2; j++)
// 			{
// 				matrix[i][j]++;
// 			}
// 		}
// 	}
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= n; j++)
// 		{
// 			if (j != 1)
// 			{
// 				cout << " ";
// 			}
// 			cout << matrix[i][j];
// 		}
// 		if (i != n)
// 		{
// 			cout << endl;
// 		}
// 	}
// 	return 0;
// }
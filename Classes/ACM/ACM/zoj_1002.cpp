#include<iostream>
using namespace std;

char mp[105][105];
int length;
int max_city;

bool in(int x, int y)
{
	return x >= 0 && x < length && y >= 0 && y < length;
}

bool in_B(int x, int y)
{
	int tx = x - 1;
	int ty = y;
	while (in(tx, ty) && mp[tx][ty] != 'X')
	{
		if (mp[tx][ty] == 'X')
		{
			break;
		}
		if (mp[tx][ty] == 'B')
		{
			return true;
		}
		tx--;
	}
	tx = x + 1;
	while (in(tx, ty) && mp[tx][ty] != 'X')
	{
		if (mp[tx][ty] == 'X')
		{
			break;
		}
		if (mp[tx][ty] == 'B')
		{
			return true;
		}
		tx++;
	}
	tx = x;
	ty = y + 1;
	while (in(tx, ty) && mp[tx][ty] != 'X')
	{
		if (mp[tx][ty] == 'X')
		{
			break;
		}
		if (mp[tx][ty] == 'B')
		{
			return true;
		}
		ty++;
	}
	ty = y - 1;
	while (in(tx, ty) && mp[tx][ty] != 'X')
	{
		if (mp[tx][ty] == 'X')
		{
			break;
		}
		if (mp[tx][ty] == 'B')
		{
			return true;
		}
		ty--;
	}
	return false;
}

void dfs(int x, int y, int city)
{
	max_city = max(max_city, city);
	if (!in(x, y) || in_B(x, y) || mp[x][y] == 'X')
	{
		return;
	}
	for (int i = x; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == x && j < y)
			{
				continue;
			}
			if (in(i, j) && !in_B(i, j) && mp[i][j] != 'B'&&mp[i][j]!='X')
			{
				mp[i][j] = 'B';
				dfs(i, j, city+1);
				mp[i][j] = '.';
			}
		}
	}
}

int main()
{
	cin >> length;
	while (length != 0)
	{
		for (int i = 0; i < length; i++)
		{
			cin >> mp[i];
		}
		max_city = 0;
		int x = 0, y = 0;
		int flag = 1;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (mp[i][j] == '.'&&flag)
				{
					x = i;
					y = j;
					flag = 0;
				}
			}
		}
		dfs(x, y, 0);
		cout << max_city <<endl;
		cin >> length;
	}
	return 0;
}
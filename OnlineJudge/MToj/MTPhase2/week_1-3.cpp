#include<iostream>
using namespace std;

int world[10010];

int main()
{
	int n;
	cin >> n;
	int max_h = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> world[i];
		max_h = max(max_h, world[i]);
	}
	int num = 0;
	for (int i = 1; i <= max_h; i++)
	{
		//每个高度找到所有相近的大于该高度的地面，统计两个之间的距离
		int left = -1;
		for (int j = 0; j < n; j++)
		{
			if (world[j] >= i)
			{
				if (left != -1)
				{
					//left已经更新过
					num += (j - left - 1);
				}
				//left初始化和使用过后的位置更新
				left = j;
			}
		}
	}
	cout << num;
	return 0;
}

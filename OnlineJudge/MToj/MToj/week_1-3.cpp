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
		//ÿ���߶��ҵ���������Ĵ��ڸø߶ȵĵ��棬ͳ������֮��ľ���
		int left = -1;
		for (int j = 0; j < n; j++)
		{
			if (world[j] >= i)
			{
				if (left != -1)
				{
					//left�Ѿ����¹�
					num += (j - left - 1);
				}
				//left��ʼ����ʹ�ù����λ�ø���
				left = j;
			}
		}
	}
	cout << num;
	return 0;
}

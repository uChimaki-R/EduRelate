#include<iostream>
using namespace std;

//Ŀ���ǲ������Ϊȫ0
//ÿ��һ���������������������������һ��һ��
//�����������������������һ�����ֻʣ��һ���������߸���
//�����Ҫ����ʣ�µ����ľ���ֵ��
//���ϣ�һ��Ҫ����ԭ������� ������ �� �����͵ľ���ֵ �еĽϴ�ֵ

int main()
{
	int n, ps = 0, ng = 0;
	int last = 0, now;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> now;
		if (i > 1)
		{
			int sub = now - last;
			if (sub > 0)
			{
				ps += sub;
			}
			else
			{
				ng -= sub;
			}
		}
		last = now;
	}
	cout << max(ps, ng);
	return 0;
}
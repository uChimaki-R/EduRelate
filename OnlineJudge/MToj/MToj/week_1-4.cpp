#include<iostream>
using namespace std;

//����ֱ����ͷ���ϵ������θ�����ͷ���µ������θ�����
// ��������n�ȷݺ���С�������α߳���Ϊ1��
//1.ͷ���ϣ�
//��n = 4Ϊ��
//�߳�Ϊ1�������θ���s1 = 1 + 2 + 3 + 4;
//            i = 2, s2 = 1 + 2 + 3;
//            i = 3, s3 = 1 + 2;
//            i = 4, s4 = 1;
//�ɴ˿��Եó�si = (n - i + 1)(n - i + 2) / 2;
//����ͷ���ϵļ�Ϊi = 1��i = n��si��ͣ�
//2.ͷ���� ��
//n = 1, s = 0;
//n = 2, s = 0 + 1;
//n = 3, s = 0 + 1 + 2;
//n = 4, s = 0 + 1 + (1 + 2 + 3);
//n = 5, s = 0 + (1 + 2) + (1 + 2 + 3 + 4��;
//n = 6, s = 0 + 1 + (1 + 2 + 3) + (1 + 2 + 3 + 4 + 5);
//�ɴ˿����Ƴ�f(n) = (1 + �� + n - i) + f(n - 2);

int up_num(int n)
{
	int up = 0;
	//�߳���1��n
	for (int i = 1; i <= n; i++)
	{
		//�ñ߳������θ���
		int num_i = 0;
		for (int j = 1; j <= n - i + 1; j++)
		{
			num_i += j;
		}
		up += num_i;
	}
	return up;
}

int down_num(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	int down = 0;
	for (int i = 1; i < n; i++)
	{
		down += i;
	}
	return down + down_num(n - 2);
}

int num(int n)
{
	return up_num(n) + down_num(n);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		cout << num(n) << endl;
	}
	return 0;
}

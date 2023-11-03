#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int v, n, m;
//sum1�����±�0�ҵ��±�i��λ����m/2��ż������һ��������Ʒ����ͼ۸�
//sum2�����±�i�ҵ��±�n-1��λ����m/2��ż������һ��������Ʒ����ͼ۸�
int sum1[100005], sum2[100005];

//ʹ�ô󶥶ѿ��Է�������۸�ĵ���ȥ
priority_queue<int>mp1, mp2;

class Sweet
{
public:
	int price, sweet;
}sw[100005];

bool mycmp(const Sweet& s1, const Sweet& s2)
{
	return s1.sweet < s2.sweet;
}

int main()
{
	cin >> v >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> sw[i].sweet >> sw[i].price;
	}
	sort(sw, sw + n, mycmp);
	//��ʼ��sum1 sum2
	sum1[0] = sw[0].price;
	mp1.push(sw[0].price);
	for (int i = 1; i < n; i++)
	{
		sum1[i] = sum1[i - 1] + sw[i].price;
		mp1.push(sw[i].price);
		if (mp1.size() > (m / 2 - 1 + m % 2))
		{
			sum1[i] -= mp1.top();
			mp1.pop();//����������
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sum2[i] = sum2[i + 1] + sw[i].price;
		mp2.push(sw[i].price);
		if (mp2.size() > (m / 2 - 1 + m % 2))
		{
			sum2[i] -= mp2.top();
			mp2.pop();//����������
		}
	}
	if (m % 2)
	{
		//����
		for (int i = n - 1 - m / 2; i >= m / 2; i--)
		{
			//i�ķ�Χ����λ����ѡ������
			//�Ӹ����ͱ�������һ������Ҫ��ľ������Ž�
			if (sum1[i - 1] + sw[i].price + sum2[i + 1] <= v)
			{
				//����۸�Ҫ��
				cout << sw[i].sweet;
				break;
			}
		}
	}
	else
	{
		//ż��
		int ans = -1;
		for (int i = m / 2 - 1; i < n - m / 2; i++)
		{
			//i�ķ�Χ�ǵ�һ����λ����ѡ������
			//��ʱi��λ���ǵ�һ����λ����λ��
			//ʹ�ö��ֲ��ҷ��ҵ��ڶ�����λ����λ��
			int l = i + 1;
			int r = n - m / 2;
			int ret = 0;
			while (l <= r)
			{
				int mid = l + (r - l) / 2;
				if (sum1[i - 1] + sw[i].price + sw[mid].price + sum2[mid + 1] <= v)
				{
					ret = mid;//������н⣬���Ҽ���Ѱ�Ҹ��Ž�
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
			ans = max(ans, (sw[i].sweet + sw[ret].sweet) / 2);
		}
		cout << ans;
	}
	return 0;
}
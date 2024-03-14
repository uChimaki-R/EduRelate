#include<iostream>
using namespace std;

const int N = 100010;

int a[N], t[N], ans[N];//ans[i]����ȥ��i֮���������record��Ӱ����
int n;

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int k)
{
	for (; x <= n; x += lowbit(x))
	{
		t[x] += k;
	}
}

int sum(int x)
{
	int ans = 0;
	for (; x; x -= lowbit(x))
	{
		ans += t[x];
	}
	return ans;
}

int main()
{
	cin >> n;
	int val, m = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> val;
		m = max(m, val);
		int s = sum(val - 1);//��valС������ǰ����ֵĴ���
		if (s == i - 1)//ȫ��������
		{
			ans[val]--;//ȥ��val��ʹ����record����1
		}
		else if (s == i - 2)//�պò�һ����˵��ǰ����һ����val��ģ�����m������i��Ϊֹ���������
		{
			ans[m]++;//ȥ����������������val��Ϊһ��record��ʹ������record����1
		}
		add(val, 1);//val���ֹ�����Ǵ���1����Ϊ�����У�����ʵ����ֻ����0/1��
	}
	int ret = 0;
	m = -0x3f3f3f3f;//Ҫ�踺������Ϊ�����ж��Ǹ���/0���������0�ͽ���ȥ�Ƚϣ��������0
	for (int i = 1; i <= n; i++)
	{
		if (m < ans[i])
		{
			ret = i;
			m = ans[i];
		}
	}
	cout << ret;
	return 0;
}
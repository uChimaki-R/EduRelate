#include<iostream>
#include<algorithm>
using namespace std;

//��״���鷽����

typedef long long LL;
const LL N = 200010;
LL n, ans;

LL lowbit(LL x)
{
	return x & -x;
}

LL arr[N], b[N], c[N];

void add(LL x, LL i)
{
	for (; x <= n; x += lowbit(x))
	{
		c[x] += i;
	}
}

LL sum(LL x)
{
	LL ret = 0;
	for (; x; x -= lowbit(x))
	{
		ret += c[x];
	}
	return ret;
}

bool cmp(const LL& a, const LL& b)
{
	if (arr[a] != arr[b])
	{
		return arr[a] < arr[b];
	}
	return a < b;
}

int main()
{
	cin >> n;
	for (LL i = 1; i <= n; i++)
	{
		cin >> arr[i];
		b[i] = i;
	}
	sort(b + 1, b + n + 1, cmp);
	//����������ɢ������ͬ����������ɢ���������ͬ��������ĿҪ����ǲ�ͬ�ģ��÷�6/10��
	////��ɢ��
	//for (LL i = 0; i < n; i++)
	//{
	//	cin >> arr[i];
	//	b[i] = arr[i];
	//}
	//sort(b, b + n);
	//LL len = unique(b, b + n) - b;
	////unique�������ظ�Ԫ�طŵ�ĩβ������û���ظ�Ԫ�ص�ĩβָ�룬-b�õ����ظ�Ԫ�ظ���
	//for (LL i = 0; i < n; i++)
	//{
	//	arr[i] = lower_bound(b, b + len, arr[i]) - b + 1;
	//	//�������������ҵ�С�ڵ��ڸ����ֵ�Ԫ��λ�ã���Ϊb������ģ����Ը�Ԫ��֮ǰ�ж���Ԫ�ؾʹ������������ԭ����ĵڼ��������
	//}
	////

	for (int i = 1; i <= n; i++)
	{
		add(b[i], 1);
		ans += sum(b[i] - 1);
	}
	//������ȼ�ԭ����˳��ԣ���Cn2��ȥ�õ������
	cout << n * (n - 1) / 2 - ans;
	return 0;
}


////ʹ�ù鲢���򷽷���
//
//#include<iostream>
//using namespace std;
//#define int long long
//
//const int N = 200010;
//
//int ans, arr[N];
//
//void merge(int arr[], int temp[], int left, int mid, int right)
//{
//	int l = left;
//	int r = mid + 1;
//	int pos = left;
//	while (l <= mid && r <= right)
//	{
//		if (arr[l] <= arr[r])
//		{
//			temp[pos++] = arr[l++];
//		}
//		else
//		{
//			ans += (mid - l + 1);
//			temp[pos++] = arr[r++];
//		}
//	}
//	while (l <= mid)
//	{
//		temp[pos++] = arr[l++];
//	}
//	while (r <= right)
//	{
//		temp[pos++] = arr[r++];
//	}
//	while (left <= right)
//	{
//		arr[left++] = temp[left];
//	}
//}
//
//void msort(int arr[], int temp[], int left, int right)
//{
//	if (left < right)
//	{
//		int mid = (left + right) >> 1;
//		msort(arr, temp, left, mid);
//		msort(arr, temp, mid + 1, right);
//		merge(arr, temp, left, mid, right);
//	}
//}
//
//void merge_sort(int arr[], int len)
//{
//	int* temp = new int[len];
//	msort(arr, temp, 0, len - 1);
//	delete[] temp;
//}
//
//signed main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	merge_sort(arr, n);
//	cout << ans;
//	return 0;
//}
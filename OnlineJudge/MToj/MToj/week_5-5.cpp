#include <iostream>
using namespace std;

int n, m;
int re = 0;
int arr[2000];

void merge(int arr[], int tempArr[], int left, int mid, int right)
{
    int l = left;
    int r = mid + 1;
    int pos = left;
    while (l <= mid && r <= right)
    {
        if (arr[l] < arr[r])
        {
            tempArr[pos++] = arr[l++];
        }
        else
        {
            // arr[l]>arr[r]说明从l到mid的所有数都比r要大，逆序数要更新
            tempArr[pos++] = arr[r++];
            re += (mid - l + 1);
        }
    }
    while (l <= mid)
    {
        tempArr[pos++] = arr[l++];
    }
    while (r <= right)
    {
        tempArr[pos++] = arr[r++];
    }
    while (left <= right)
    {
        arr[left] = tempArr[left];
        left++;
    }
}

void msort(int arr[], int tempArr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        msort(arr, tempArr, left, mid);
        msort(arr, tempArr, mid + 1, right);
        merge(arr, tempArr, left, mid, right);
    }
}

void merge_sort(int arr[], int len)
{
    int *tempArr = new int[len];
    msort(arr, tempArr, 0, len - 1);
    delete[] tempArr;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    // 使用归并排序求逆序数
    merge_sort(arr, n);
    // //测试
    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl
    //      << re << endl;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        re = re + (r - l + 1) * (r - l) / 2;
        if (re % 2)
        {
            // 奇数
            cout << "odd" << endl;
        }
        else
        {
            // 偶数
            cout << "even" << endl;
        }
    }
    return 0;
}
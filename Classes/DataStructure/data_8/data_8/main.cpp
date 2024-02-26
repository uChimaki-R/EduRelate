#include <iostream>
#include <vector>
using namespace std;

int n, times;

// 打印数组内容
void printArray(const vector<int>& arr) {
	cout << "[" << times << "]  ";
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;
	times++;
}

// 快速排序
void quickSort(vector<int>& arr, int left, int right) {
	if (left >= right) return;

	int pivot = arr[left];
	int i = left, j = right;

	while (i < j) {
		while (i < j && arr[j] >= pivot) j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot) i++;
		arr[j] = arr[i];
	}
	arr[i] = pivot;
	printArray(arr);

	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}

// 冒泡排序
void bubbleSort(vector<int> arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
		printArray(arr);
	}
}

// 直接选择排序
void selectionSort(vector<int> arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
		printArray(arr);
	}
}


int main() {
	vector<int> arr;
	cout << "数组元素个数：";
	cin >> n;
	cout << "输入数组元素：";
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr.push_back(val);
	}

	cout << "冒泡排序过程：" << endl;
	times = 0;
	printArray(arr);
	bubbleSort(arr);

	cout << "直接选择排序过程：" << endl;
	times = 0;
	printArray(arr);
	selectionSort(arr);

	cout << "快速排序过程：" << endl;
	times = 0;
	printArray(arr);
	quickSort(arr, 0, arr.size() - 1);

	return 0;
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int binary_search(int arr[], int n, int target) {
//	int left = 0;
//	int right = n - 1;
//
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//
//		if (arr[mid] == target) {
//			return mid;
//		}
//		else if (arr[mid] < target) {
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	return -1;
//}
//
//int main() {
//	int n, target;
//	int* arr = new int[10000];
//
//	cout << "请输入数组元素个数：";
//	cin >> n;
//
//	cout << "请输入数组元素：";
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//
//	cout << "请输入需要搜索的数字：";
//	cin >> target;
//
//	int result = binary_search(arr, n, target);
//
//	if (result != -1) {
//		cout << "元素 " << target << " 在数组中的索引为： " << result << endl;
//	}
//	else {
//		cout << "元素 " << target << " 不在数组中" << endl;
//	}
//
//	delete[]arr;
//	return 0;
//}

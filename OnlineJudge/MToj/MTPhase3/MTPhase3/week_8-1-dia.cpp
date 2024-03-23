#include<iostream>
using namespace std;

int arr[300];
int temp[300];

// 编码
//void code(int* arr, int len) {
//	if (len == 0)return;
//	int half = len / 2;
//	for (int i = 0; i < half; i++) {
//		temp[i] = arr[2 * i] + arr[2 * i + 1];
//		temp[half + i] = arr[2 * i] - arr[2 * i + 1];
//	}
//	for (int i = 0; i < len; i++) {
//		arr[i] = temp[i];
//	}
//	code(arr, half);
//}

// 解码
void decode(int* arr, int now, int len) {
	if (now == len * 2)return;
	int half = now / 2;
	int p = 0;
	for (int i = 0; i < half; i++) {
		int apb = arr[i], adb = arr[half + i];
		temp[p++] = (apb + adb) / 2;
		temp[p++] = (apb - adb) / 2;
	}
	for (int i = 0; i < now; i++) {
		arr[i] = temp[i];
	}
	decode(arr, now * 2, len);
}

int main() {
	while (true) {
		int len = 0;
		cin >> len;
		if (!len)break;
		for (int i = 0; i < len; i++)cin >> arr[i];
		decode(arr, 2, len);
		for (int i = 0; i < len - 1; i++)cout << arr[i] << " ";
		cout << arr[len - 1] << endl;
	}
	return 0;
}
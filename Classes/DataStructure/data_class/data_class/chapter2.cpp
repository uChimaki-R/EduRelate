#include <iostream>
#include <algorithm>
using namespace std;

void deleteElement(int A[], int& arrsize, int x) {
    int i;
    for (i = 0; i < arrsize; i++) {
        if (A[i] == x) {
            break;
        }
    }
    if (i < arrsize) {
        for (int j = i; j < arrsize - 1; j++) {
            A[j] = A[j + 1];
        }
        arrsize--;
    }
}

int main() {
    int arrsize, x, * A;
    cin >> arrsize;
    A = new int[arrsize];
    for (int i = 0; i < arrsize; i++)
        cin >> A[i];
    sort(A, A + arrsize);
    for (int i = 0; i < arrsize; i++) {
        cout << A[i] << " ";
    }
    cin >> x;
    deleteElement(A, arrsize, x);
    for (int i = 0; i < arrsize; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
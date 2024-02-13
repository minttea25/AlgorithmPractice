#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(int* arr, int start, int end) {
    // if the length == 1
    if (start >= end) return;

    // Set pivot first value of arr
    int pivot = start;    

    int left = start + 1;
    int right = end;

    // It would reduce time to sort
    swap(arr[left], arr[(start + end) >> 1]);

    while(left <= right) {
        while(left <= end && arr[left] <= arr[pivot]) left++;

        while(right > start && arr[right] >= arr[pivot]) right--;

        if (left > right) {
            swap(arr[right], arr[pivot]);
        }
        else {
            swap(arr[left], arr[right]);
        }
    }

    quick_sort(arr, start, right-1);
    quick_sort(arr, right+1, end);
}

void printArr(int* arr, int len) {
    for(int i=0; i<len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int arr1[10] = { 2, 4, 1, 6, 9, 5, 5, 3, 0, 7 };
    int arr2[10] = { 2, 4, 1, 6, 9, 5, 5, 3, 0, 7 };

    cout << "Original array (not sorted)" << endl;
    printArr(arr1, 10);

    cout << endl;

    sort(arr1, arr1+10);
    cout << "Sorted by sort() in <algorithm>" << endl;
    printArr(arr1, 10);

    cout << endl;

    cout << "Sorted by quick_sort() of user-defined function" << endl;
    quick_sort(arr2, 0, 9);
    printArr(arr2, 10);

    return 0;
}
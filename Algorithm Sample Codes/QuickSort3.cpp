#include <iostream>
#include <vector>
using namespace std;

// 배열을 분할하고 피벗의 최종 위치를 반환하는 함수
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // 마지막 요소를 피벗으로 선택
    int i = (low - 1);  // 작은 요소의 인덱스

    for (int j = low; j < high; j++) {
        // 현재 요소가 피벗보다 작거나 같다면
        if (arr[j] <= pivot) {
            i++;  // 작은 요소를 찾으면 인덱스를 증가
            swap(arr[i], arr[j]);  // 현재 요소와 교환
        }
    }
    // 피벗을 정렬된 위치로 이동
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QuickSort 구현
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // 피벗을 기준으로 분할한 후, 피벗의 인덱스를 반환
        int pi = partition(arr, low, high);

        // 피벗을 기준으로 두 부분 배열을 재귀적으로 정렬
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

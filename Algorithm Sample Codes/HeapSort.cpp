#include <iostream>
#include <vector>
using namespace std;

// 힙을 정렬하는 함수
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // 루트를 가장 큰 값으로 가정
    int left = 2 * i + 1;  // 왼쪽 자식
    int right = 2 * i + 2;  // 오른쪽 자식

    // 왼쪽 자식이 루트보다 크다면
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 가장 큰 값보다 크다면
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 루트가 가장 큰 값이 아니라면 교환
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // 교환 후, 자식 노드에 대해 다시 heapify 호출
        heapify(arr, n, largest);
    }
}

// HeapSort 구현
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 최대 힙을 빌드
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 하나씩 요소를 힙에서 꺼내어 정렬
    for (int i = n - 1; i > 0; i--) {
        // 현재 루트(최대값)를 배열의 끝으로 보냄
        swap(arr[0], arr[i]);
        // 남은 배열에 대해 heapify 호출
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);

    cout << "Sorted array is \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

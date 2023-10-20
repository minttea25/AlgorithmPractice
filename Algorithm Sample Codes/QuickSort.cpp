#include <iostream>
#include <random>
#include <vector>

using namespace std;

#define PRINT(v) for(int i=0; i<v.size(); ++i) std::cout << v[i] << ' '; std::cout << '\n'


void quickSort(vector<int>& arr, const int left, const int right) {
    // base case
    if (left >= right) return;

    int pivot = left;

    const int size = arr.size();

    int l = left + 1;
    int r = right;

    while (l <= r) {
        while (l < size && arr[l] <= arr[pivot]) l++;
        while (r < size && arr[r] > arr[pivot]) r--;

        if (l <= r) {
            swap(arr[l], arr[r]);
        }
        else {
            swap(arr[r], arr[pivot]);
        }
    }

    quickSort(arr, left, r - 1);
    quickSort(arr, r+1, right);
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(-100, 100);

    vector<int> v;

    for(int i=0; i<10; i++) {
        int t = distribution(gen);
        v.push_back(t);
    }

    PRINT(v);

    quickSort(v, 0, 9);

    PRINT(v);

    return 0;
}
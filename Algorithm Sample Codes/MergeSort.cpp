#include <iostream>
#include <vector>
#include <random>

using namespace std;

#define PRINT(v) for(int i=0; i<v.size(); ++i) std::cout << v[i] << ' '; std::cout << '\n'

void mergeSort(vector<int>& arr, const int left, const int right) {
    if (left == right) return;

    int mid = (left + right) >> 1;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    // deep copy
    vector<int> l_arr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> r_arr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int l_size = l_arr.size();
    int r_size = r_arr.size();
    int l_idx = 0;
    int r_idx = 0;
    int i = left;

    while (l_idx < l_size && r_idx < r_size) {
        if (l_arr[l_idx] <= r_arr[r_idx]) {
            arr[i] = l_arr[l_idx];
            l_idx++;
        }
        else {
            arr[i] = r_arr[r_idx];
            r_idx++;
        }
        ++i;
    }

    if (l_idx == l_size) {
        copy(r_arr.begin() + r_idx, r_arr.end(), arr.begin() + i);
    }
    else {
        copy(l_arr.begin() + l_idx, l_arr.end(), arr.begin() + i);
    }
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

    mergeSort(v, 0, 9);

    PRINT(v);

    return 0;
}
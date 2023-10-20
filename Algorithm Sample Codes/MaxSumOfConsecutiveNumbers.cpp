#include <iostream>
#include <random>

#define PRINT(v) for(int i=0; i<v.size(); ++i) std::cout << v[i] << ' '; std::cout << '\n'

using namespace std;

const int MIN = std::numeric_limits<int>::min();

int getMaxSum(const vector<int>& v) {
    const int s = v.size();
    int ret = MIN;

    for (int i=0; i<s; ++i) {
        for (int j=i; j<s; ++j) {
            int sum = 0;
            for (int k=i; k<j+1; ++k) {
                sum += v[k];
            }
            ret = max(sum, ret);
        }
    }

    return ret;
}

int getMaxSum2(const vector<int>& v) {
    const int s = v.size();
    int ret = MIN;

    for (int i=0; i<s; ++i) {
        int sum = 0;
        for (int j=i; j<s; ++j) {
            sum += v[j];
            ret = max(sum, ret);
        }
    }

    return ret;
}

int getMaxSum3(const vector<int>& v, const int left, const int right) {
    if (left == right) return v[left];

    int mid = (left + right) >> 1;
    int l = MIN;
    int r = MIN;
    int sum = 0;

    // l + r 시에 연속된 배열이어야 하기 때문에 mid 부터 하나씩 내려감!
    for (int i=mid; i>=left; --i) {
        sum += v[i];
        l = max(sum, l);
    }

    sum = 0;

    for (int i=mid+1; i<=right; ++i) {
        sum += v[i];
        r = max(sum, r);
    }

    int single = max(getMaxSum3(v, left, mid), getMaxSum3(v, mid+1, right));
    return max(single, l + r);
}

int getMaxSum4(const vector<int>& v) {
    const int s = v.size();
    int ret = MIN;

    int psum = 0;
    for(int i=0; i<s; ++i) {
        psum = max(psum, 0) + v[i];
        //psum = max(psum + v[i], v[i]);
        ret = max(ret, psum);
    }

    return ret;
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(-10, 10);

    vector<int> v;

    for(int i=0; i<10; i++) {
        v.push_back(distribution(gen));
    }

    PRINT(v);

    auto n3 = getMaxSum(v);
    cout << n3 << endl;

    auto n2 = getMaxSum2(v);
    cout << n2 << endl;

    auto lgn = getMaxSum3(v, 0, 9);
    cout << lgn << endl;

    auto n = getMaxSum4(v);
    cout << n << endl;

    return 0;
}
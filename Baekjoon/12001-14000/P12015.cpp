// 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

using namespace std;

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

constexpr int DUMMY = -1;

int N;
iv _input;

iv lMax;

void LIS() {
    lMax.push_back(DUMMY);

    FOR(i, 0, N) {
        if (lMax.back() < _input[i]) {
            lMax.push_back(_input[i]);
        }
        else {
            lMax[lower_bound(lMax.begin(), lMax.end(), _input[i])-lMax.begin()] = _input[i];
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    FOR(i, 0, N) {
        int t;
        cin >> t;
        _input.push_back(t);
    }

    LIS();

    cout << lMax.size() - 1 << endl;

    return 0;
}
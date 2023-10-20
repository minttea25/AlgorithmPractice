// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003

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

constexpr int DUMMY = -1'234'567'890;

int N;
iv _input;
iv lMax;
iv minIdx;

void LIS() {
    lMax.push_back(DUMMY);

    FOR(i, 0, N) {
        if (lMax.back() < _input[i]) {
            lMax.push_back(_input[i]);
            minIdx.push_back(lMax.size()-1);
        }
        else {
            auto it = lower_bound(lMax.begin(), lMax.end(), _input[i])-lMax.begin();
            lMax[it] = _input[i];
            minIdx.push_back(it);
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

    iv iAns;
    for(int i=N-1, n=lMax.size()-1; n>0; --i) {
        if (minIdx[i] == n) {
            iAns.push_back(_input[i]);
            --n;
        }
    }

    // print ans
    for(int i=iAns.size()-1; i>=0; --i) {
        cout << iAns[i] << ' ';
    }
    cout << endl;

    return 0;
}
// 가장 긴 증가하는 부분 수열
// https://www.acmicpc.net/problem/11053

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
int arr[1001];

iv lMax;

void LIS() {
    lMax.push_back(DUMMY);

    FOR(i, 0, N) {
        if (lMax.back() < arr[i]) {
            lMax.push_back(arr[i]);
        }
        else {
            lMax[lower_bound(lMax.begin(), lMax.end(), arr[i])-lMax.begin()] = arr[i];
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    FOR(i, 0, N) {
        cin >> arr[i];
    }

    LIS();

    cout << lMax.size() - 1 << endl;

    return 0;
}
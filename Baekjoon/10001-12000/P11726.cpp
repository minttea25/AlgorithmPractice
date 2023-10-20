// 2xn 타일링
// https://www.acmicpc.net/problem/11726

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
constexpr int MOD = 10007;

int N;
ll memoi[1001];

ll memoization(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (memoi[n] != DUMMY) return memoi[n];

    return memoi[n] = (memoization(n-1) + memoization(n-2))%MOD;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    memset(memoi, DUMMY, sizeof(memoi));

    cin >> N;

    cout << memoization(N) << endl;

    return 0;
}
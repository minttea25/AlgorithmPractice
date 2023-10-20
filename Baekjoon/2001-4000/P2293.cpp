// 동전 1
// https://www.acmicpc.net/problem/2293

#include <iostream>
#include <vector>
#include <algorithm>

// It includes almost all header files for algorithm practice.
// It is not a standard library header for C++, but a valid header only with the gcc compiler.
// #include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

int coins[101];
int ans[10001];
int N, K;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    FOR(i, 0, N) {
        cin >> coins[i];
    }

    ans[0] = 1;

    FOR(i, 0, N) {
        FOR_(j, coins[i], K) {
            ans[j] += ans[j - coins[i]];
        }
    }

    cout << ans[K] << endl;

    return 0;
}
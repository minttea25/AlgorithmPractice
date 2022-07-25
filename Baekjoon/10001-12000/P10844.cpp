// 쉬운 계단 수
// https://www.acmicpc.net/problem/10844

#include <iostream>
#include <vector>
#include <algorithm>

// It includes almost all header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
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

constexpr ll DIVISOR = 1000000000LL; // 제수

int N;
ll dp[11][101];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    // dp[v][d]: the count of stair-number at v and d
    // v: 0-9; the last number of stair-number
    // d: 1-100; the digit of stair-number

    // dp[0][1] = 0; // initialized to 0 at declaration
    // dp[10][1] = 0; // same as upper
    FOR_(i, 1, 9) {
        dp[i][1] = 1; 
    }
    
    // dp[v][d] = dp[v+1][d-1] + dp[v-1][d-1]
    FOR_(i, 2, N) {
        dp[0][i] = dp[1][i-1]; // dp[-1][i-1] = 0
        FOR_(j, 1, 9) {
            dp[j][i] += dp[j+1][i-1] % DIVISOR;
            dp[j][i] += dp[j-1][i-1] % DIVISOR;
            dp[j][i] %= DIVISOR;
        }
    }

    ll ans = 0;
    FOR_(i, 0, 9) {
        ans += dp[i][N];
    }

    cout << ans%DIVISOR << endl;

    return 0;
}
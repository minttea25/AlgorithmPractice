// 설탕 배달
// https://www.acmicpc.net/problem/2839

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost all header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
// #include <bits/stdc++.h>

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

constexpr int DEFAULT = 1000000;

int dp[5001];

int getDP(int n) {
    if (dp[n] != 0) return dp[n];

    if (n%5 == 0) {
        dp[n] = n/5;
    }
    else {
        int mn = 10000;
        for(int i=n-3, cnt=1; i>=0; i-=3, cnt++) {
            if (i%5 == 0) {
                mn = min(mn, getDP(i) + cnt);
            }
        }
        if (mn == 10000) {
            dp[n] = -1;
        }
        else {
            dp[n] = mn;
        }
    }
    return dp[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = dp[2] = dp[4] = -1;
    dp[3] = 1;
    dp[5] = 1;

    cout << getDP(N) << endl;

    return 0;
}
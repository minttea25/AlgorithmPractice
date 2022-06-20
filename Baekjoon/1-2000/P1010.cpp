// 다리 놓기
// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost header files for algorithm practice.
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

int dp[31][16];

int t;

// mCn
int com(int n, int m) {
    if (m-n < n) n = m-n;

    if (n==m || n==0) return 1;
    else if (n==1) return m;

    if (dp[m][n] == 0) {
        dp[m-1][n-1] = com(n-1,m-1);
        dp[m-1][n] = com(n, m-1);

        dp[m][n] = dp[m-1][n-1] + dp[m-1][n];
    }

    return dp[m][n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;

    cin >> t;

    FOR(i, 0, t) {
        cin >> n >> m;

        cout << com(n, m) << endl;
    }

    return 0;
}

// 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775

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

int T, k, n;
int memoi[1001][1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    FOR(i, 1, 1001) {
        memoi[0][i] = i;
        memoi[i][1] = 1;
    }
    FOR(i, 1, 1001) {
        FOR(j, 2, 1001) {
            memoi[i][j] = memoi[i-1][j] + memoi[i][j-1];
        }
    }

    cin >> T;

    FOR(i, 0, T) {
        cin >> k >> n;
        cout << memoi[k][n] << endl;
    }

    return 0;
}
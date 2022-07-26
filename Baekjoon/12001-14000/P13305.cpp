// 주유소
// https://www.acmicpc.net/problem/13305

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

constexpr int MAX = 100001;

int p[MAX];
int dist[MAX];
int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    FOR(i, 0, N-1) {
        cin >> dist[i];
    }
    FOR(i, 0, N) {
        cin >> p[i];
    }

    ll ans = 0;
    int d = 0;
    int p_mn = p[0];
    FOR(i, 1, N) {
        d += dist[i-1];

        if (p_mn > p[i] || i == N-1) {
            ans += (ll)d*p_mn;
            p_mn = p[i];
            d = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
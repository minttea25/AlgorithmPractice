// 센서
// https://www.acmicpc.net/problem/2212

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

int N, K;
int inp[100001];
int dist[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    FOR(i, 0, N) {
        cin >> inp[i];
    }

    sort(inp, inp+N);

    int start = inp[0];
    FOR(i, 1, N) {
        int t = inp[i];
        dist[i-1] = t - start;
        start = t;
    }

    sort(dist, dist+N-1);

    int sum = 0;
    FOR(i, 0, N-K) {
        sum += dist[i];
    }

    cout << sum << endl;

    return 0;
}
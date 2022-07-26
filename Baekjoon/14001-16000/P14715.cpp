// 전생했더니 슬라임 연구자였던 건에 대하여 (Easy)
// https://www.acmicpc.net/problem/14715

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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

#define DEFAULT 0

constexpr int MAX = 1000001;

int depth[MAX];
int K;

int divSlime(int e) {
    if (depth[e] != DEFAULT) return depth[e];

    iv v;

    FOR_(i, 2, floor(sqrt(e))) {
        if (e%i == 0) v.push_back(i);
    }

    if (v.size() == 0) return depth[e] = 0;

    int mn = INT_MAX;
    for (int value : v) {
        int m = max(divSlime(value) + 1, divSlime(e/value) + 1);
        mn = min(m, mn);
    }

    return depth[e] = mn;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> K;

    cout << divSlime(K) << endl;

    return 0;
}
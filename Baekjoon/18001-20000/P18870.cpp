// 좌표 압축
// https://www.acmicpc.net/problem/18870

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

iv input;
iv v;
int n;
int t;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> n;

    FOR(i, 0, n)
    {
        cin >> t;
        input.push_back(t);
        v.push_back(t);
    }

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    FOR(i, 0, n) {
        auto tt = std::lower_bound(v.begin(), v.end(), input[i]);
        size_t idx = std::distance(v.begin(), tt);
        cout << idx << ' ';
    }
    cout << endl;

    return 0;
}
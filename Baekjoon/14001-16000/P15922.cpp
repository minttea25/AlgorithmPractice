// 아우으 우아으이야!!
// https://www.acmicpc.net/problem/15922

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

int coords[100001][2];
int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    FOR(i, 0, N) {
        cin >> coords[i][0] >> coords[i][1];
    }

    int sum = 0; // max(sum) = 2,000,000,000
    int left = - 1000000001;
    int right = - 1000000001;
    FOR(i, 0, N) {
        // previous line contains coords[i]
        if (right  >= coords[i][1]) {
            continue;
        }
        // partially overlapped or connected
        else if (right >= coords[i][0] && right < coords[i][1]) {
            right = coords[i][1];
        }
        // apart
        else if (right < coords[i][0]){
            sum += right - left;
            left = coords[i][0];
            right = coords[i][1];
        }
    }
    // calc last one
    sum += right - left;

    cout << sum << endl;

    return 0;
}
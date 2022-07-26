// 전생했더니 슬라임 연구자였던 건에 대하여 (Hard)
// https://www.acmicpc.net/problem/14698

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

typedef unsigned long long ull;

const ull DEVIDE = 1000000007LL;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    priority_queue<ull, vector<ull>, greater<ull>> pq;

    int T;
    ull t;
    int slimes;
    ull a, b, s;
    ull sum = 1;
    cin >> T;
    for(int i=0; i<T; i++) {
        sum = 1;
        cin >> slimes;

        for(int j=0; j<slimes; j++) {
            cin >> t;
            pq.push(t);
        }

        while(true) {
            a = pq.top();
            pq.pop();
            if (pq.empty()) {
                break;
            }
            b = pq.top();
            pq.pop();

            s = a*b;
            sum = (sum * (s%DEVIDE))%DEVIDE;
            pq.push(s);
        }
        cout << sum << '\n';
    }

    return 0;
}
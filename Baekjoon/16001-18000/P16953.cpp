// A -> B
// https://www.acmicpc.net/problem/16953

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

queue<ll> q;
int A, B;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> A >> B;

    int lv = 1;

    q.push(A);
    q.push(-1);

    while(q.size() > 1) {
        ll p = q.front();
        q.pop();
        if (p == -1) {
            lv++;
            q.push(-1);
            continue;
        }
        else {
            if (p == B) {
                cout << lv << '\n';
                return 0;
            }

            long long a = p * 2;
            long long b = p * 10 + 1;

            if (a >= 1 && a <= 1000000000) {
                q.push(a);
            }

            if (b >= 1 && b <= 1000000000) {
                q.push(b);
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}
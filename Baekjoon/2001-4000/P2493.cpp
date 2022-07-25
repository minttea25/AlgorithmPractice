// 탑
// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <vector>
#include <algorithm>

#include <stack>

// It includes almost all header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
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

constexpr int MAX = 500001;

stack<iip> stk;
int b[MAX];
int ans[MAX];
int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int t;

    cin >> N;
    FOR_(i, 1, N) {
        cin >> b[MAX-N-1+i];
    }

    FOR_(i, 1, N) {
        t = b[MAX-i];

        while(!stk.empty() && t > stk.top().first) {
            ans[stk.top().second] = N-i+1;
            stk.pop();
        }

        stk.push({t, i});
    }

    iFOR_(i, N, 1) {
        cout << ans[i] << ' ';
    }

    return 0;
}
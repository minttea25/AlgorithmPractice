// 안정적인 문자열
// https://www.acmicpc.net/problem/4889

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// It includes almost all header files for algorithm practice.
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

constexpr char open = '{';
constexpr char close = '}';

string s;
stack<char> stk;

int solve(string s) {
    int ans = 0;
    stack<char> stk;

    FOR(i, 0, s.length()) {
        if (stk.size() == 0) {
            if (s[i] == close) ans++;
            stk.push(open);
        }
        else {
            if (s[i] == close) stk.pop();
            else stk.push(open);
        }
    }

    ans += stk.size()/2;

    return ans;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int ans;
    int T = 0;
    while(true) {
        cin >> s;
        if (s[0] == '-') break;
        T++;

        cout << T << ". " << solve(s) << endl;
    }

    return 0;
}
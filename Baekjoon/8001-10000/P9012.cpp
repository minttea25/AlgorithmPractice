// 괄호
// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

int T;

bool checkBracket(string s) {
    int stk = 0;
    FOR(i, 0, s.length()) {
        switch (s[i])
        {
        case '(':
            stk++;
            break;
        case ')':
            stk--;
            break;
        default:
            break;
        }

        if (stk < 0) return false;
    }
    return stk==0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> T;
    FOR(i, 0, T) {
        cin >> s;
        cout << (checkBracket(s) ? "YES" : "NO") << endl;
    }

    return 0;
}
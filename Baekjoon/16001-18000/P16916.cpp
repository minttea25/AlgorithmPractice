// 부분 문자열
// https://www.acmicpc.net/problem/16916

#include <iostream>
#include <vector>
#include <algorithm>

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

constexpr int MAX = 1000001;

int failure[MAX];
string s;
string ss;

void initFailure() {
    for(int i=1, j=0; i<ss.length(); i++) {
        while(j > 0 && ss[i] != ss[j]) {
             j = failure[j-1];
        }
        if (ss[i] == ss[j]) {
            j++;
            failure[i] = j;
        }
    }
}

bool KMP() {
    for (int i=0, j=0; i<s.length(); i++) {
        while(j>0 && (s[i] != ss[j])) {
            j = failure[j-1];
        }
        if (s[i] == ss[j]) {
            if (j == ss.length() - 1) {
                return true;
            }
            else {
                j++;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> s;
    cin >> ss;

    initFailure();

    cout << (KMP() ? 1 : 0) << endl;

    return 0;
}
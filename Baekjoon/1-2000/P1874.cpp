// 스택 수열
// https://www.acmicpc.net/problem/1874

#include <iostream>
#include <vector>
#include <stack>

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

stack<int> st;
int n;
int input[100001];
char output[200002];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> n;

    FOR(i, 0, n) {
        cin >> input[i];
    }

    int a = 1;
    int outputIdx = 0;
    int pointer = 0; // seq index
    output[outputIdx++] = '+';
    st.push(a++);

    while(pointer < n) {
        if (!st.empty() && input[pointer] == st.top()) {
            st.pop();
            pointer++;
            output[outputIdx++] = '-';
        }
        else {
            if (a > n+1) {
                break;
            }
            output[outputIdx++] = '+';
            st.push(a++);
        }
    }

    if (st.empty()) {
        FOR(i, 0, outputIdx) {
            cout << output[i] << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
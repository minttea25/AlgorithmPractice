// 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002

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

constexpr int MAX = 100001;

int n;
vector<int> lastInput;

int inputs[MAX];
int lis[MAX];

int invInputs[MAX];
int tInvLis[MAX];
int invLis[MAX];

int lMax[MAX];

int mx;

void LIS(int in[], int out[], int n) {
    lastInput.clear();

    vector<int>::iterator it;
    lastInput.push_back(-1); // we don't use value at index=0

    for (int i=1; i<=n; i++) {
        if (lastInput.back() < in[i]) {
            lastInput.push_back(in[i]); 
        }
        // 크거나 같은 값 중 가장 작은 수를 가져옴
        it = lower_bound(lastInput.begin(), lastInput.end(), in[i]);
        *it = in[i];
        out[i] = it - lastInput.begin();

        mx = max(mx, out[i]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    mx = -1;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> inputs[i];
    }

    LIS(inputs, lis, n);


    FOR(i, 1, n+1) {
        invInputs[n-i+1] = MAX - inputs[i];
    }
    LIS(invInputs, tInvLis, n);
    FOR(i, 1, n+1) {
        invLis[n-i+1] = tInvLis[i];
    }

    lMax[0] = -1;
    FOR(i, 1, n+1) {
        if (lis[i] + invLis[i] == mx + 1) {
            lMax[i] = max(lMax[i-1], inputs[i]);
        }
        else {
            lMax[i] = lMax[i-1];
        }
    }

    // print ans

    cout << mx << endl;

    int prev = lMax[0];
    FOR(i, 1, n+1) {
        if (prev != lMax[i]) {
            prev = lMax[i];
            cout << lMax[i] << ' ';
        }
    }
    cout << endl;

    return 0;
}
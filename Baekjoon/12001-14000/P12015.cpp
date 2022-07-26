// 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015

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

#define DUMMY -1

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

const int MAX = 1000001;

int n;
vector<int> lastInput;

int inputs[MAX];
int lis[MAX];

int mx;

void LIS(int in[], int out[], int n) {
    lastInput.clear();

    vector<int>::iterator it;
    lastInput.push_back(DUMMY); // we don't use value at index=0

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

    cout << mx << endl;

    return 0;
}
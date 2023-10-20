// ATM
// https://www.acmicpc.net/problem/11399

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

int arr[1000];
int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    FOR(i, 0, N) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int total = 0;
    FOR(i, 0, N) {
        total += arr[i] * (N-i);
    }

    cout << total << endl;

    return 0;
}
// N - Queen
// https://www.acmicpc.net/problem/9663

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

constexpr int MAX = 15;

int col[MAX];
int N;
int cnt;

bool isPossibleToSet(int n) {
    FOR(i, 0, n) {
        // same row || same diagonal
        if (col[i] == col[n] || n - i == abs(col[i] - col[n])) {
            return false;
        }
    }

    return true;
}

void nQueen(int n) {
    // all queens are located in proper locations.
    if (n == N) {
        cnt++;
        return;
    }

    FOR(i, 0, N) {
        col[n] = i; // locate quuen (n, i)
        if (isPossibleToSet(n)) {
            nQueen(n+1); // check next coordinates
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    nQueen(0);
    
    cout << cnt << endl;

    return 0;
}
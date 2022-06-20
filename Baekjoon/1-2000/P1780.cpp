// 종이의 개수
// https://www.acmicpc.net/problem/1780

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

int N;
int P[2188][2188];
int NUM[3] = {0, };

void calcCount(int a, int b, int size) {
    bool allSame = true;
    int n = P[a][b];
    FOR(i, a, a+size) {
        FOR(j, b, b+size) {
            if (P[i][j] != n) {
                allSame = false;
                break;
            }
        }
    }

    if (allSame) NUM[n+1]++;
    else {
        int nextSize = size/3;
        FOR(i, 0, 3) {
            FOR(j, 0, 3) {
                calcCount(a+i*nextSize, b+j*nextSize, nextSize);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> P[i][j];
        }
    }

    calcCount(0, 0, N);

    for(int nn : NUM) {
        cout << nn << endl;
    }

    return 0;
}
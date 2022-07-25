// 정수 삼각형
// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <vector>
#include <algorithm>

// It includes almost all header files for algorithm practice.
// It is not standard library header of C++, and used o only gcc compiler.
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

int tri[501][501];
int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    
    FOR_(i, 1, N) {
        FOR(j, 0, i) {
            cin >> tri[i][j];
        }
    }

    FOR_(i, 1, N) {
        FOR(j, 0, i) {
            // left
            if (j == 0) {
                tri[i][j] = tri[i-1][j] + tri[i][j];
            }
            // right
            else if (j == i-1) {
                tri[i][j] = tri[i-1][j-1] + tri[i][j];
            }
            // else
            else {
                tri[i][j] = max(tri[i-1][j], tri[i-1][j-1]) + tri[i][j];
            }
        }
    }

    int mx = -1;
    FOR(i, 0, N) {
        mx = max(mx, tri[N][i]);
    }

    cout << mx << endl;

    return 0;
}
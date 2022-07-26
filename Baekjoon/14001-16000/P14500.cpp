// 테트로미노
// https://www.acmicpc.net/problem/14500

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

constexpr int MAX = 500;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int maps[MAX][MAX] = {false, };
bool visited[MAX][MAX];
int N, M, mx;

void dfs(const int r, const int c, const int depth, int sum) {
    if (depth == 3) {
        mx = max(mx, sum);
        return;
    }

    visited[r][c] = true;

    for (int d=0; d<4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        // check boundary
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) {
            continue;
        }
        dfs(nr, nc, depth+1, sum+maps[nr][nc]);
        visited[nr][nc] = false;
    }
    visited[r][c] = false;
}

void checkShape4(const int r, const int c) {
    int tmp;
    // 8 cases
    if (r-2 >= 0) {
        tmp = maps[r][c]+maps[r-1][c]+maps[r-2][c];
        if (c-1 >= 0) {
            mx = max(mx, tmp + maps[r-1][c-1]);
        }
        if (c+1 < M) {
            mx = max(mx, tmp + maps[r-1][c+1]);
        }
    }

    if (r+2 < N) {
        tmp = maps[r][c]+maps[r+1][c]+maps[r+2][c];
        if (c-1 >= 0) {
            mx = max(mx, tmp + maps[r+1][c-1]);
        }
        if (c+1 < M) {
            mx = max(mx, tmp + maps[r+1][c+1]);
        }
    }

    if (c-2 >= 0) {
        tmp = maps[r][c]+maps[r][c-1]+maps[r][c-2];
        if (r-1 >= 0) {
            mx = max(mx, tmp + maps[r-1][c-1]);
        }
        if (r+1 < N) {
            mx = max(mx, tmp + maps[r+1][c-1]);
        }
    }

    if (c+2 < M) {
        tmp = maps[r][c]+maps[r][c+1]+maps[r][c+2];
        if (r-1 >= 0) {
            mx = max(mx, tmp + maps[r-1][c+1]);
        }
        if (r+1 < N) {
            mx = max(mx, tmp + maps[r+1][c+1]);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    mx = -1;

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            dfs(i, j, 0, maps[i][j]);
            checkShape4(i, j);
        }
    }

    cout << mx << endl;

    return 0;
}
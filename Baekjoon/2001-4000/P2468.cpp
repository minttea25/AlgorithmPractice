// 안전구역
// https://www.acmicpc.net/problem/2468

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

constexpr int VISITED = 100;

constexpr iip dir[4] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
int map[101][101];
int m[101][101];
int N;

void bfs(int x, int y) {
    queue<int> xq;
    queue<int> yq;
    xq.push(x); yq.push(y);
    m[x][y] = VISITED;

    while(!xq.empty()) {
        int px = xq.front(); xq.pop();
        int py = yq.front(); yq.pop();

        for(iip d : dir) {
            int dx = px + d.first;
            int dy = py + d.second;

            if (dx < 0 || dx >= N || dy < 0 || dy >= N || m[dx][dy] == VISITED || m[dx][dy] <= 0) {
                continue;
            }
            else {
                m[dx][dy] = VISITED;
                xq.push(dx);
                yq.push(dy);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int mx = -1;

    cin >> N;

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> map[i][j];
            mx = max(mx, map[i][j]);
        }
    }

    int ans = 0;
    FOR_(i, 0, mx) {
        int cnt = 0;
        FOR(j, 0, N) {
            FOR(k, 0, N) {
                m[j][k] = map[j][k] - i;
            }
        }

        FOR(j, 0, N) {
            FOR(k, 0, N) {
                if (m[j][k] > 0 && m[j][k] != VISITED) {
                    bfs(j, k);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
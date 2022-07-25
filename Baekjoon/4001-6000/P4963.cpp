// 섬의 개수
// https://www.acmicpc.net/problem/4963

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

iip dir[8] = {
    {0, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}
};

bool map[51][51];
int N, M;

void bfs(int x, int y) {
    queue<iip> q;
    q.push({x, y});
    map[x][y] = false;

    while(!q.empty()) {
        iip t = q.front();
        q.pop();

        for (iip d : dir) {
            int xx = t.first + d.first;
            int yy = t.second + d.second;

            if (xx < 0 || xx >= M || yy < 0 || yy >= N || !map[xx][yy]) {
                continue;
            }
            else {
                map[xx][yy] = false;
                q.push({xx, yy});
            }
        }
    }
}

int connectedComponents() {
    int cnt = 0;

    FOR(i, 0, M) {
        FOR(j, 0, N) {
            if (map[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    while(true) {
        cin >> N >> M;

        if (N == 0 && M == 0) break;

        FOR(i, 0, M) {
            fill_n(map[i], N, false);
            FOR(j, 0, N) {
                cin >> map[i][j];
            }
        }

        cout << connectedComponents() << endl;
    }

    return 0;
}
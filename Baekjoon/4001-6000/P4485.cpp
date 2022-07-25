// 녹색 옷 입은 애가 젤다지?
// https://www.acmicpc.net/problem/4485

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

//typedef tuple<int, int, int> e; // cost, x, y
typedef pair<int, iip> e;

constexpr int MAX = 125+1;

priority_queue<e> q;

int map[MAX][MAX];
int dist[MAX][MAX];
int N;

iip dir[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void dijkstra(int locX, int locY, int cost) {
    q.push({-cost, {locX, locY}});
    dist[locX][locY] = cost;

    while(!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();

        for (iip d : dir) {
            int xx = x + d.first;
            int yy = y + d.second;

            if (xx < 0 || xx >= N || yy < 0 || yy >= N) continue;

            if (dist[xx][yy] > dist[x][y] + map[xx][yy]) {
                dist[xx][yy] = dist[x][y] + map[xx][yy];
                q.push({-dist[xx][yy], {xx, yy}});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int T = 1;

    while(true) {
        cin >> N;
        if (N == 0) break;

        FOR(i, 0, N) {
            FOR(j, 0, N) {
                cin >> map[i][j];
            }
            fill_n(dist[i], N, 100000000);
        }

        dijkstra(0, 0, map[0][0]);

        cout << "Problem " << T << ": " << dist[N-1][N-1] << endl;
        T++;
    }

    return 0;
}
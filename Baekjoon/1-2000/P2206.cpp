// 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>

#define E(r, c, b) make_pair(make_pair(r, c), b)
#define RANGE(r, c, n, m) (r >= 0 && r < n && c >= 0 && c < m)

#define endl '\n'
using namespace std;

using E = pair<pair<int, int>, bool>;

constexpr bool WALL = 1;
constexpr bool PATH = 0;

constexpr int MAX = 1'000'000'000;
constexpr pair<int, int> dirs[] =
{
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

constexpr pair<int, int> b_dirs[] =
{
    {-2, 0}, {2, 0}, {0, -2}, {0, 2},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

int bfs(const vector<vector<bool>>& map)
{
    const int n = map.size();
    const int m = map[0].size();

    int dist[n][m][2];
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            dist[i][j][0] = MAX;
            dist[i][j][1] = MAX;
        }
    }

    queue<E> q;
    q.push(E(0, 0, false));
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;

    while (q.empty() == false)
    {
        auto [r, c] = q.front().first;
        bool b = q.front().second;
        q.pop();

        for (const auto& [dr, dc] : dirs)
        {
            int nr = r + dr;
            int nc = c + dc;

            if (RANGE(nr, nc, n, m) == true)
            {
                if (b == true)
                {
                    if (map[nr][nc] == WALL) continue;

                    if (dist[nr][nc][1] > dist[r][c][1] + 1)
                    {
                        dist[nr][nc][1] = dist[r][c][1] + 1;
                        q.push(E(nr, nc, b));
                    }
                }
                else
                {
                    if (map[nr][nc] == PATH)
                    {
                        if (dist[nr][nc][0] > dist[r][c][0] + 1)
                        {
                            dist[nr][nc][0] = dist[r][c][0] + 1;
                            q.push(E(nr, nc, b));
                        }
                    }
                    else
                    {
                        for (const auto& [bdr, bdc] : b_dirs)
                        {
                            int bnr = r + bdr;
                            int bnc = c + bdc;

                            if (RANGE(bnr, bnc, n, m) == true)
                            {
                                if (map[bnr][bnc] == WALL) continue;

                                if (dist[bnr][bnc][1] > dist[r][c][0] + 2
                                    && dist[bnr][bnc][0] > dist[r][c][0] + 2)
                                {
                                    dist[bnr][bnc][1] = dist[r][c][0] + 2;
                                    q.push(E(bnr, bnc, true));
                                }
                            }
                        }
                    }
                }
            }
        }
    }    

    return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> map(n, vector<bool>(m));
    for(int i=0; i<n; ++i)
    {
        string s;
        cin >> s;
        for(int j=0; j<m; ++j)
        {
            map[i][j] = s[j]=='0' ? PATH : WALL;
        }
    }

    int ans = bfs(map);

    cout << (ans==MAX ? -1 : ans) << endl;

    return 0;
}
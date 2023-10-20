// 쉬운 최단 거리
// https://www.acmicpc.net/problem/14940

#include <iostream>
#include <vector>
#include <queue>

#define _x(p) p.first
#define _y(p) p.second

using namespace std;

using pos = pair<int, int>;

constexpr pos dir[] =
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
constexpr int WALL = 0;
constexpr int FIELD = -1;
constexpr pos DUMMY = {-9999, -9999};

void bfs(const pos start, vector<vector<int>>& map, const int n, const int m)
{
    int depth = 0;
    queue<pos> q;

    q.push(start);
    map[_y(start)][_x(start)] = 1; // temp

    q.push(DUMMY);

    while (q.empty() == false)
    {
        auto current = q.front();
        q.pop();

        if (current == DUMMY)
        {
            if (q.empty() == false)
            {
                q.push(DUMMY);
                depth++;
            }
        }

        for(const pos& d : dir)
        {
            int xx = _x(current) + _x(d);
            int yy = _y(current) + _y(d);

            if(xx >= 0 && xx < m && yy >= 0 && yy < n)
            {
                int& p = map[yy][xx];
                if (p == FIELD)
                {
                    q.push({xx, yy});
                    p = depth + 1;
                }
            }
        }
    }

    map[_y(start)][_x(start)] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    pos start;
    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == 2) start = {j, i};

            map[i][j] *= -1;
        }
    }

    bfs(start, map, n, m);

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}
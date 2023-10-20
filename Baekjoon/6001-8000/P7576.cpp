// 토마토
// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <queue>

#define _x(pos) pos.first
#define _y(pos) pos.second

using namespace std;

using pos = pair<int, int>;

constexpr pos DUMMY = {-1, -1};
constexpr pos dir[4] = 
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};
constexpr int EMPTY = -1;
constexpr int TOMATO = 0;
constexpr int RIPPED = 1;

bool checkAllRipped(const vector<vector<int>>& box)
{
    const int size = box.size();
    for(int i=0; i<size; ++i)
    {
        for(const int& t : box[i])
        {
            if (t == TOMATO) return false;
        }
    }
    return true;
}

int bfs(const vector<pos> starts, vector<vector<int>>& box, const int m, const int n)
{
    int days = 0;

    queue<pos> q;

    for(const pos& s : starts) 
    {
        q.push(s);
        box[_y(s)][_x(s)] = RIPPED;
    }
    q.push(DUMMY);

    while (q.empty() == false)
    {
        pos current = q.front();
        q.pop();

        if (current == DUMMY)
        {
            if (q.empty() == false)
            {
                days++;
                q.push(DUMMY);
                continue;
            }
            else break;
        }

        for(const pos& d : dir)
        {
            int xx = _x(current) + _x(d);
            int yy = _y(current) + _y(d);
            if (xx >= 0 && xx < m && yy >= 0 && yy < n)
            {
                if (box[yy][xx] == TOMATO)
                {
                    box[yy][xx] = RIPPED;
                    q.push({xx, yy});
                }
            }
        }
    }

    return days;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m, -1));
    vector<pos> starts;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> box[i][j];
            if (box[i][j] == RIPPED) starts.push_back({j, i});
        }
    }

    int days = bfs(starts, box, m, n);

    if (checkAllRipped(box) == true) cout << days << '\n';
    else cout << -1 << '\n';

    return 0;
}
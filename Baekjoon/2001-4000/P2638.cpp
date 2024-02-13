// 치즈
// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>

#define endl '\n'

using namespace std;

using pos = pair<int, int>;

constexpr int EMPTY = 0;
constexpr int CHEESE = 1;

constexpr int AIR = 2;
constexpr int INNER = 3;

constexpr pos dir[] =
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void bfs(vector<vector<int>>& map, const pos start, const int value)
{
    const int X = map[0].size();
    const int Y = map.size();

    queue<pos> q;
    q.push(start);

    while (q.empty() == false)
    {
        auto pop = q.front();
        q.pop();

        for (auto d : dir)
        {
            int x = pop.first + d.first;
            int y = pop.second + d.second;
            if (x < 0 || x >= X || y < 0 || y >= Y) continue;

            if (map[y][x] == CHEESE) continue;
            if (map[y][x] == AIR) continue;

            map[y][x] = value;
            q.push({x, y});
            //cout << y << ' ' << x << endl;
        }
    }
}

void set_empty_inner(vector<vector<int>>& map)
{
    for(auto row : map)
    {
        for(auto c : row)
        {
            if (c == EMPTY) c = INNER;
        }
    }
}

bool will_melt(pos cheese_pos, vector<vector<int>>& map)
{
    int cnt = 0;
    for (auto d : dir)
    {
        int x = cheese_pos.first + d.first;
        int y = cheese_pos.second + d.second;
        if (x >= 0 && x < map[0].size() && y >= 0 && y < map.size())
        {
            if (map[y][x] == AIR) cnt++;
        }
    }
    if (cnt >= 2) return true;
    else return false;
}

// do zero-padding
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<pos> cheese;
    vector<vector<int>> map(n, vector<int>(m, EMPTY));

    for(int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int input;
            cin >> input;
            map[i][j] = input;
            if (input == CHEESE) cheese.push_back({j, i});
        }
    }

    map[0][0] = AIR;
    bfs(map, {0, 0}, AIR);
    set_empty_inner(map);

    int time = 0;

    // start to melt
    while (true)
    {
        vector<pos> t;
        for (auto c : cheese)
        {
            if (will_melt(c, map) == true)
            {
                t.push_back({c.first, c.second});
            }
        }

        // melt
        for(auto m : t)
        {
            map[m.second][m.first] = AIR;
            bfs(map, m, AIR);
            
            auto it = find(cheese.begin(), cheese.end(), m);
            if (it != cheese.end()) cheese.erase(it);
        }

        time++;
        if (cheese.size() == 0) break;
    }

    cout << time << endl;

    return 0;
}
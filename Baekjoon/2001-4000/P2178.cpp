// 미로 탐색
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
#include <queue>

#define _x(pos) pos.second 
#define _y(pos) pos.first

using namespace std;

using pos = pair<int, int>;

constexpr char PATH = '1';
constexpr char WALL = '0';
constexpr pos DUMMY = {-1, -1};
constexpr pos dir[4] = 
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int bfs(vector<string>& map)
{
    const int n = map.size();
    const int m = map[0].size();

    int count = 1;
    queue<pos> q;

    q.push({0, 0});
    map[0][0] = WALL;

    q.push(DUMMY);

    while(q.empty() == false)
    {
        pos current = q.front();
        q.pop();

        if (current == DUMMY)
        {
            if (q.empty()) return -1; // error
            q.push(DUMMY);
            count++;
            continue;
        }

        for(const pos& d : dir)
        {
            const int xx = _x(current) + _x(d);
            const int yy = _y(current) + _y(d);

            if (xx == m-1 && yy == n-1) 
            {
                return count+1;
            }
            else if (xx >= 0 && xx < m && yy >= 0 && yy < n)
            {
                if (map[yy][xx] == PATH)
                {
                    map[yy][xx] = WALL;
                    q.push({yy, xx});
                }
            }
        }
    }

    // unreachable code
    return -1;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<string> map;

    int n, m;
    cin >> n >> m;

    cin.ignore(10000, '\n');
    for(int i=0; i<n; ++i)
    {
        string hor;
        getline(cin, hor);
        map.push_back(hor);
    }

    cout << bfs(map) << '\n';

    return 0;
}
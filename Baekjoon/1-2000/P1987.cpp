// 알파벳
// https://www.acmicpc.net/problem/1987

#include <iostream>
#include <vector>
#include <queue>

#define OUT
#define _A(c) c-'A'

#define _x(pos) pos.first
#define _y(pos) pos.second

using namespace std;

using pos = pair<int, int>;

constexpr pos DUMMY = { -1, -1 };
constexpr pos dir[4] = 
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

constexpr unsigned int add(const int n, const unsigned int& s)
{
    unsigned int nSet = s | (1 << n);
    return nSet;
}

constexpr bool contains(const int n, const unsigned int& s)
{
    return s&(1 << n);
}

int bfs(const vector<vector<char>>& map)
{
    const pos start = {0, 0};
    const unsigned int s = add(_A(map[0][0]), 0);
    const int r = map.size();
    const int c = map[0].size();

    int count = 0;
    queue<pair<pos, unsigned int>> q;

    q.push({start, s});
    q.push({DUMMY, 0});

    while(q.empty() == false)
    {
        auto cur = q.front();
        q.pop();

        if(cur.first == DUMMY)
        {
            count++;
            if (q.empty() == true) break;
            q.push({DUMMY, 0});
        }

        for(const auto& d : dir)
        {
            int xx = _x(cur.first) + _x(d);
            int yy = _y(cur.first) + _y(d);

            if (xx >= 0 && xx < c && yy >= 0 && yy < r)
            {
                const int ch = _A(map[yy][xx]);
                cout << "visited: " << (char)(ch + 'A') << endl;
                if (contains(ch, cur.second) == false)
                {
                    unsigned int nSet = add(ch, cur.second);
                    q.push(make_pair(make_pair(xx, yy), nSet));
                }
            }
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c, 0));
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            cin >> map[i][j];
        }
    }

    cout << bfs(map) << '\n';

    return 0;
}
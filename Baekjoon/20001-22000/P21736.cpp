// 헌내기는 친구가 필요해
// https://www.acmicpc.net/problem/21736

#include <iostream>
#include <vector>
#include <queue>

#define _x(pos) pos.first
#define _y(pos) pos.second

using namespace std;

using pos = pair<int, int>;

pos dir[] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
// compile-constant
constexpr char EMPTY = 'O';
constexpr char WALL = 'X';
constexpr char DOYEON = 'I';
constexpr char PERSON = 'P';

const string FAIL = "TT"; // runtime-constant

int bfs(vector<string>& map, const pos start, const int m, const int n)
{
    int count = 0;
    queue<pos> q;

    q.push(start);
    map[_y(start)][_x(start)] = WALL;

    while (q.empty() == false)
    {
        pos current = q.front();
        q.pop();

        for(const pos& d : dir)
        {
            int xx = _x(current) + _x(d);
            int yy = _y(current) + _y(d);

            if (xx >= 0 && xx < n && yy >= 0 && yy < m)
            {   
                char& next = map[yy][xx];

                if (next == EMPTY)
                {
                    next = WALL;
                    q.push({xx, yy});
                }
                else if (next == PERSON)
                {
                    next = WALL;
                    count++;
                    q.push({xx, yy});
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

    int m, n;
    cin >> m >> n;

    vector<string> map;

    pos start = {-1, -1};
    for(int i=0; i<m; ++i)
    {
        string s;
        cin >> s;
        map.push_back(s);

        if (start.first != -1) continue;
        for(int ii=0; ii<s.size(); ++ii)
        {
            if (s[ii] == DOYEON)
            {
                start = {ii, i};
                break;
            }
        }
    }

    const int count = bfs(map, start, m, n);
    if (count == 0) cout << FAIL << '\n';
    else cout << count << '\n';

    return 0;
}
// 유기농 배추
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

using pii = pair<int, int>;

constexpr int MAX = 50 + 1;
constexpr int dir[4][2] =
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

bool field[MAX][MAX];

void bfs(const pii pos, const int m, const int n)
{
    queue<pii> q;

    q.push(pos);
    field[pos.first][pos.second] = false;

    while(q.empty() == false)
    {
        pii now = q.front();
        q.pop();

        for(int i=0; i<4; ++i)
        {
            int yy = now.first + dir[i][0];
            int xx = now.second + dir[i][1];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n)
            {
                if (field[yy][xx] == true)
                {
                    field[yy][xx] = false;
                    q.push({yy, xx});
                }
            }
        }
    }
}

int solve(const int m, const int n)
{
    int count = 0;
    
    for(int x=0; x<m; ++x)
    {
        for(int y=0; y<n; ++y)
        {
            if (field[y][x] == true)
            {
                bfs({y, x}, m, n);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int tc;
    cin >> tc;

    int m; // 가로길이 [1, 50]
    int n; // 세로길이 [1, 50]
    int k; // 배추 위치 개수 [1, 2500]
    
    for(int i=0; i<tc; ++i)
    {
        memset(field, false, sizeof(field));

        cin >> m >> n >> k;

        for(int ii=0; ii<k; ++ii)
        {
            // 배추 위치
            // X, Y
            int x, y;
            cin >> x >> y;
            field[y][x] = true;
        }

        

        cout << solve(m, n) << '\n';
    }


    return 0;
}
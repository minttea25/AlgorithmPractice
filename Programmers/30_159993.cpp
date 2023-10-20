// 미로 탈출
// https://school.programmers.co.kr/learn/courses/30/lessons/159993

#include <string>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

constexpr char START = 'S';
constexpr char EXIT = 'E';
constexpr char LEVER = 'L';
constexpr char PATH = 'O';
constexpr char WALL = 'X';
constexpr pii DUMMY = { -1, -1 };

constexpr pii dir[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

char mapp[101][101];
bool visited[101][101];
int x_size;
int y_size;
bool found = false;

int bfs(pii pos, const char target)
{
    int depth = 0;
    queue<pii> q;
    visited[pos.first][pos.second] = true;
    q.push(pos);
    q.push(DUMMY);

    while (q.size() != 0)
    {
        auto p = q.front();
        q.pop();

        if (p == DUMMY)
        {
            if (q.size() == 0) break;
            depth++;
            q.push(DUMMY);
            continue;
        }

        for (auto& d : dir)
        {
            int x = p.first + d.first;
            int y = p.second + d.second;
            if (x >= 0 && x < x_size && y >= 0 && y < y_size)
            {
                if (visited[x][y] == true) continue;
                if (target == LEVER)
                {
                    if (mapp[x][y] == PATH || mapp[x][y] == EXIT)
                    {
                        visited[x][y] = true;
                        q.push({ x, y });
                    }
                    else if (mapp[x][y] == target)
                    {
                        found = true;
                        return depth+1;
                    }
                }
                else if (target == EXIT)
                {
                    if (mapp[x][y] == PATH || mapp[x][y] == LEVER || mapp[x][y] == START)
                    {
                        visited[x][y] = true;
                        q.push({ x, y });
                    }
                    else if (mapp[x][y] == target)
                    {
                        found = true;
                        return depth+1;
                    }
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps)
{
    int time = 0;

    x_size = maps[0].size();
    y_size = maps.size();
    pii start;
    pii lever;

    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            mapp[j][i] = maps[i][j];
            if (mapp[j][i] == START) start = { j, i };
            else if (mapp[j][i] == LEVER) lever = { j, i };
        }
    }

    int t1 = bfs(start, LEVER);;
    if (found == false)
    {
        return -1;
    }

    for (int i = 0; i < x_size; i++)
    {
        memset(visited[i], false, y_size * sizeof(bool));
    }
    found = false;

    int t2 = bfs(lever, EXIT);
    if (found == false)
    {
        return -1;
    }

    return t1+t2;
}
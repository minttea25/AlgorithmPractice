// 치즈
// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <vector>
#include <queue>

constexpr char AIR = 0;
constexpr char EMPTY = 1;
constexpr char CHEESE = 2;

struct Vector2Int
{
public:
    int x, y;
};
static Vector2Int operator+(const Vector2Int& a, const Vector2Int& b) { return Vector2Int{ a.x + b.x, a.y + b.y }; }

using Map = std::vector<std::vector<char>>;

constexpr Vector2Int Near[] =
{
    Vector2Int{1, 0},
    Vector2Int{-1, 0},
    Vector2Int{0, 1},
    Vector2Int{0, -1},
};

constexpr bool CheckBound(const Vector2Int& pos, const int n, const int m)
{
    return pos.x >= 0 && pos.x < n && pos.y >= 0 && pos.y < m;
}

bool MeltCheese(const Map& map, const Vector2Int& cheese)
{
    int count = 0;
    for (const auto& near : Near)
    {
        auto pos = near + cheese;
        if (map[pos.x][pos.y] == AIR) count++;
    }
    return count >= 2;
}

void FindAir(Map& map, const std::vector<Vector2Int>& start)
{
    // fixed start position

    const int n = map.size();
    const int m = map[0].size();

    // find AIR with bfs
    std::queue<Vector2Int> q;
    for (auto& s : start)
    {
        if (map[s.x][s.y] == AIR) continue;

        q.push(s);
        map[s.x][s.y] = AIR;

        while (q.empty() == false)
        {
            auto current = q.front();
            q.pop();

            for (const auto& near : Near)
            {
                auto pos = current + near;
                if (CheckBound(pos, n, m) && map[pos.x][pos.y] == EMPTY)
                {
                    q.push(pos);
                    map[pos.x][pos.y] = AIR;
                }
            }
        }
    }
}

int MeltCheese(Map& map, const std::vector<Vector2Int>& cheese, std::vector<Vector2Int>& changed)
{
    int count = 0;
    for (const auto& c : cheese)
    {
        if (map[c.x][c.y] != CHEESE) continue;
        if (MeltCheese(map, c) == true)
        {
            map[c.x][c.y] = EMPTY;
            count ++;
            changed.push_back(c);
        }
    }
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Map map(n, std::vector<char>(m));
    std::vector<Vector2Int> cheese;
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<m; ++ii)
        {
            int t;
            std::cin >> t;
            map[i][ii] = t == 0 ? EMPTY : CHEESE;

            if (map[i][ii] == CHEESE) cheese.push_back(Vector2Int{i, ii});
        }
    }

    std::vector<Vector2Int> changed{
        Vector2Int{0, 0},
        Vector2Int{n-1, 0},
        Vector2Int{0, m-1},
        Vector2Int{n-1, m-1},
        };
    int count = cheese.size();
    int days = 0;
    while (true)
    {
        FindAir(map, changed);
        changed.clear();
        auto c = MeltCheese(map, cheese, changed);
        days++;
        count -= c;

        if (count == 0) break;
    }

    std::cout << days << std::endl;


    return 0;
}
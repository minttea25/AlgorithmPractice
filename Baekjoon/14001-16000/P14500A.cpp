// 테트로미노
// https://www.acmicpc.net/problem/14500

#include <iostream>
#include <vector>
#include <algorithm>

using Pos = std::pair<int, int>;
using Map = std::vector<std::vector<int>>;

constexpr bool CheckRange(const Pos& pos, const int& max_first, const int& max_second)
{
    return pos.first >=0 && pos.first < max_first && pos.second >=0 && pos.second < max_second;
}

static Pos operator+(const Pos& lhs, const Pos& rhs)
{
    return Pos{lhs.first + rhs.first, lhs.second + rhs.second};
}

struct Tetromino
{
public:
    int sum(const Pos& base, const Map& map) const
    {
        int s = 0;
        for (const auto& m : Members)
        {
            s += map[base.first + m.first][base.second + m.second];
        }
        return s;
    }

    int sum(const Pos& base, const Map& map, const int& n, const int& m) const
    {
        if (CheckRange(base + Members[3], n, m) == false) return 0;
        return sum(base, map);
    }
public:
    const Pos Members[4];
};

struct Area
{
public:
    int max_sum(const Pos& base, const Map& map, const int& n, const int& m) const
    {
        if (CheckRange(base + MaxRange, n, m) == false) return 0;
        int mx = 0;
        for (const auto& m : Members)
        {
            mx = std::max(mx, m.sum(base, map));
        }
        return mx;
    }
public:
    const Pos MaxRange;
    const Tetromino Members[4];
};

constexpr Area Areas[4] =
{
    {
        {1, 2},
        {
            { { {0, 0}, {0, 1}, {0, 2}, {1, 2} } }, 
            { { {0, 0}, {0, 1}, {0, 2}, {1, 1} } }, 
            { { {0, 0}, {0, 1}, {1, 1}, {1, 2} } }, 
            { { {0, 0}, {1, 0}, {1, 1}, {1, 2} } }
        }
    },
    {
        {-1, 2},
        {
            { { {0, 0}, {0, 1}, {0, 2}, {-1, 2} } }, 
            { { {0, 0}, {0, 1}, {0, 2}, {-1, 1} } }, 
            { { {0, 0}, {0, 1}, {-1, 1}, {-1, 2} } }, 
            { { {0, 0}, {-1, 0}, {-1, 1}, {-1, 2} } }
        }
    },
    {
        {2, 1},
        {
            { { {0, 0}, {1, 0}, {2, 0}, {2, 1} } }, 
            { { {0, 0}, {1, 0}, {2, 0}, {1, 1} } }, 
            { { {0, 0}, {1, 0}, {1, 1}, {2, 1} } }, 
            { { {0, 0}, {0, 1}, {1, 1}, {2, 1} } }
        }
    },
    {
        {2, -1},
        {
            { { {0, 0}, {1, 0}, {2, 0}, {2, -1} } }, 
            { { {0, 0}, {1, 0}, {2, 0}, {1, -1} } }, 
            { { {0, 0}, {1, 0}, {1, -1}, {2, -1} } }, 
            { { {0, 0}, {0, -1}, {1, -1}, {2, -1} } }
        }
    }
};


constexpr Tetromino Cases[] =
{
    { { {0, 0}, {0, 1}, {0, 2}, {0, 3} } },
    { { {0, 0}, {1, 0}, {2, 0}, {3, 0} } },
    { { {0, 0}, {0, 1}, {1, 0}, {1, 1} } }
};

int CheckCases(const Pos& base, const Map& map, const int& n, const int& m)
{
    int mx = 0;
    for (const auto& a : Areas)
    {
        mx = std::max(mx, a.max_sum(base, map, n, m));
    }
    for (const auto& t : Cases)
    {
        mx = std::max(mx, t.sum(base, map, n, m));
    }
    return mx;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Map map(n, std::vector<int>());
    for (int i=0; i < n; ++i)
    {
        for (int j=0; j < m; ++j)
        {
            int input;
            std::cin >> input;
            map[i].push_back(input);
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<m; ++ii)
        {
            ans = std::max(CheckCases({i, ii}, map, n, m), ans);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
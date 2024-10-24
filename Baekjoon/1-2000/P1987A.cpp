// 알파벳
// https://www.acmicpc.net/problem/1987

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define TO_INDEX(c) c - 'A'

using Graph = std::vector<std::vector<char>>;
using Pos = std::pair<int, int>;

static Pos operator+(const Pos& lhs, const Pos& rhs)
{
    return { lhs.first + rhs.first, lhs.second + rhs.second };
}

constexpr Pos Directions[] =
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

constexpr bool CheckRange(const Pos& pos, const int& max_first, const int& max_second)
{
    return pos.first >= 0 && pos.first < max_first && pos.second >=0 && pos.second < max_second;
}

constexpr void add(unsigned int& set, const int value)
{
    set |= (1 << value);
}

constexpr bool contains(unsigned int& set, const int value)
{
    return set & (1 << value);
}
constexpr int count(unsigned int& set)
{
    return __builtin_popcount(set);
}

int search_bfs(const Pos& pos, const Graph& graph)
{
    const int r = graph.size();
    const int c = graph[0].size();

    unsigned int passed = 0; // 32bit

    struct Status { Pos pos; unsigned int set; };
    int mx = 0;
    std::queue<Status> q;
    add(passed, TO_INDEX(graph[pos.first][pos.second]));
    q.push({pos, passed});

    while (q.empty() == false)
    {
        auto current = q.front();
        q.pop();

        mx = std::max(mx, count(current.set));

        for (const auto& dir : Directions)
        {
            auto next = current.pos + dir;
            if (CheckRange(next, r, c)
                && contains(current.set, TO_INDEX(graph[next.first][next.second])) == false)
            {
                auto s = current.set;
                add(s, TO_INDEX(graph[next.first][next.second]));
                q.push({next, s});
            }
        }
    }

    return mx;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int r, c;
    std::cin >> r >> c;

    Graph graph(r, std::vector<char>());
    for (int i=0; i<r; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int ii=0; ii<s.size(); ++ii)
        {
            graph[i].push_back(s[ii]);
        }
    }

    int mx = search_bfs({0, 0}, graph);

    std::cout << mx << std::endl;

    return 0;
}
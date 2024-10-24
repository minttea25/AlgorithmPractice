// 단지번호붙이기
// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

static constexpr int HOUSE = 1;
static constexpr int EMPTY = 0;

struct Pos
{
public:
    int r; int c;

    Pos operator+(const Pos& other)
    {
        return {r + other.r, c + other.c};
    }
};

constexpr Pos Directions[] = 
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

constexpr bool CheckRange(const Pos& pos, const int& n)
{
    return pos.r >= 0 && pos.c >= 0 && pos.r < n && pos.c < n;
}

int connected_components(const Pos& start, std::vector<std::vector<int>>& map, const int n)
{
    int count = 0;
    std::stack<Pos> s;

    s.push(start);
    map[start.r][start.c] = EMPTY;

    while (s.empty() == false)
    {
        auto current = s.top();
        s.pop();
        count++;

        for(auto& dir : Directions)
        {
            auto next = current + dir;

            if (CheckRange(next, n) && map[next.r][next.c] == HOUSE)
            {
                s.push(next);
                map[next.r][next.c] = EMPTY;
            }
        }
    }

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> map(n, std::vector<int>());

    for (int i=0; i<n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int ii=0; ii<n; ++ii)
        {
            map[i].push_back((int)(s[ii] - '0'));
        }
    }

    std::vector<int> ans;
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<n; ++ii)
        {
            if (map[i][ii] == HOUSE)
            {
                int count = connected_components({i, ii}, map, n);
                ans.push_back(count);
            }
        }
    }

    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << '\n';
    for (auto& v : ans)
    {
        std::cout << v << '\n';
    }

    return 0;

}
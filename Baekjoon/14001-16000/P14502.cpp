// 연구소
// https://www.acmicpc.net/problem/14502

#include <vector>
#include <iostream>
#include <queue>

using Map = std::vector<std::vector<int>>;
using Pos = std::pair<int, int>;

constexpr int EMPTY = 0;
constexpr int WALL = 1;
constexpr int VIRUS = 2;

constexpr int BUILT_IN_WALL_COUNT = 3;

constexpr bool CheckRange(const Pos& pos, const int& max_first, const int& max_second)
{
    return pos.first >=0 && pos.first < max_first && pos.second >=0 && pos.second < max_second;
}

static Pos operator+(const Pos& lhs, const Pos& rhs)
{
    return Pos{lhs.first + rhs.first, lhs.second + rhs.second};
}

constexpr Pos Directions[] =
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

/// @brief 
/// @param virus 
/// @param map 
/// @param walls 
/// @return total count of virus after spreading
int spread(const std::vector<Pos>& virus, const Map& map)
{
    const int n = map.size();
    const int m = map[0].size();
    std::vector<bool> visited(n * m, false);

    int count = 0;
    std::queue<Pos> q;
    for (const auto& v : virus)
    {
        q.push(v);
        visited[v.first * m + v.second] = true;
        count++;
    }

    while (q.empty() == false)
    {
        auto current = q.front();
        q.pop();

        for (const auto& d : Directions)
        {
            auto next = d + current;
            if (CheckRange(next, n, m) 
                && visited[next.first * m + next.second] == false
                && map[next.first][next.second] == EMPTY)
            {
                q.push(next);
                visited[next.first * m + next.second] = true;
                count++;
            }
        }
    }

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Map map(n, std::vector<int>());
    std::vector<Pos> empty_space;
    std::vector<Pos> virus;
    int wall_size = 0;
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<m; ++ii)
        {
            int input;
            std::cin >> input;
            map[i].push_back(input);

            if (input == EMPTY) empty_space.push_back({i, ii});
            else if (input == VIRUS) virus.push_back({i, ii});
            else if (input == WALL) wall_size++;
        }
    }

    int ans = 0;
    int size = empty_space.size();
    for (int i=0; i<size-2; ++i)
    {
        map[empty_space[i].first][empty_space[i].second] = WALL;
        for (int ii=i+1; ii<size-1; ++ii)
        {
            map[empty_space[ii].first][empty_space[ii].second] = WALL;
            for (int iii=ii+1; iii<size; ++iii)
            {
                map[empty_space[iii].first][empty_space[iii].second] = WALL;

                int virus_size = spread(virus, map);
                int safe_size = n * m - virus_size - wall_size - BUILT_IN_WALL_COUNT;
                ans = std::max(ans, safe_size);

                map[empty_space[iii].first][empty_space[iii].second] = EMPTY;
            }
            map[empty_space[ii].first][empty_space[ii].second] = EMPTY;
        }
        map[empty_space[i].first][empty_space[i].second] = EMPTY;
    }

    std::cout << ans << std::endl;

    return 0;
}
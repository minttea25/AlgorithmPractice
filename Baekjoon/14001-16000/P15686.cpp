// 치킨 배달
// https://www.acmicpc.net/problem/15686

#include <vector>
#include <iostream>
#include <algorithm>

using Pos = std::pair<int, int>;

constexpr int HOUSE = 1;
constexpr int STORE = 2;

constexpr int CalcDist(const Pos& p1, const Pos& p2)
{
    int a = p1.first - p2.first;
    int b = p1.second - p2.second;
    return ((a < 0) ? (a * -1) : a) + ((b < 0) ? (b * -1) : b);
}

struct ChickenDist
{
public:
    int store;
    int dist;

    bool operator<(const ChickenDist& other) const
    {
        return dist < other.dist;
    }
};

using Map = std::vector<std::vector<ChickenDist>>;


int tracking(const Map& map, std::vector<bool>& stores, const int m, const int depth, const int now)
{
    if (depth == m)
    {
        int dist = 0;
        for (int i=0; i<map.size(); ++i)
        {
            for (const auto& cd : map[i])
            {
                if (stores[cd.store] == true)
                {
                    dist += cd.dist;
                    break;
                }
            }
        }
        return dist;
    }

    int mn = 9999999;

    for (int i=now; i<stores.size(); ++i)
    {
        stores[i] = true;
        mn = std::min(mn, tracking(map, stores, m, depth + 1, i + 1));
        stores[i] = false;
    }

    return mn;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Pos> houses;
    std::vector<Pos> stores;
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<n; ++ii)
        {
            int input;
            std::cin >> input;
            if (input == HOUSE) houses.push_back({i, ii});
            else if (input == STORE) stores.push_back({i, ii});
        }
    }

    // make map
    // house - ChickenDist
    Map map(houses.size(), std::vector<ChickenDist>());
    for (int i=0; i<houses.size(); ++i)
    {
        for (int ii=0; ii<stores.size(); ++ii)
        {
            map[i].push_back({ii, CalcDist(stores[ii], houses[i])});
        }
        std::sort(map[i].begin(), map[i].end());
    }

    std::vector<bool> visited(stores.size(), false);
    int ans = tracking(map, visited, m, 0, 0);

    std::cout << ans << std::endl;

    return 0;
}
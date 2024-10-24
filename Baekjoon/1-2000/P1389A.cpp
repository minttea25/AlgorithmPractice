// 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389

#include <queue>
#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using Element = std::pair<int, int>; // value - person

int dijkstra(const Graph& relations, const int start)
{
    const int size = relations.size();

    std::vector<int> dist(size, 999999);

    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;

    dist[start] = 0;
    pq.push(std::make_pair(0, start));
    while (pq.empty() == false)
    {
        auto distance = pq.top().first;
        auto person = pq.top().second;
        pq.pop();

        // need not to calculate the distance. Already minimum distance.
        if(distance > dist[person]) continue;

        for (const auto& f : relations[person])
        {
            const int nextDistance = distance + 1; // w is always 1
            // if the nextDistance is smaller than calcuated distance
            if (nextDistance < dist[f])
            {
                // set min distance
                dist[f] = nextDistance;
                // add it into pq
                pq.push({nextDistance, f});
            }
        }
    }

    // all vertexes are connected. (No dist is not default value)
    int sum = 0;
    for (auto& d : dist) sum += d;
    return sum;
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);


    int n; // number of friends
    int m; // number of relationships

    std::cin >> n >> m;

    Graph relations(n, std::vector<int>());
    for (int i=0; i<m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        relations[u-1].push_back(v-1);
        relations[v-1].push_back(u-1);
    }

    int ans = 99999999;
    int mn = 99999999;
    for (int i=0; i<n; ++i)
    {
        const int v = dijkstra(relations, i);
        if (mn > v)
        {
            mn = v;
            ans = i;
        }
    }

    std::cout << ans + 1 << std::endl;

    return 0;
}
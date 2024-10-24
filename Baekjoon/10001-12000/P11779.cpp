// 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779

#include <iostream>
#include <vector>
#include <queue>

struct Bus
{
public:
    int v; // destination
    int w;
};

struct BusComparator
{
    bool operator()(const Bus& lhs, const Bus& rhs)
    {
        return lhs.w > rhs.w;
    }
};

// city -> {destination, cost}
using Graph = std::vector<std::vector<Bus>>;

int dijkstra(const Graph& graph, const int start, const int destination, std::vector<int>& parent)
{
    const int size = graph.size(); // size of cities
    parent.assign(size, -1);
    std::vector<int> dist(size, 99'999'999); // min cost
    
    dist[start] = 0; // set 0 at start node

    std::priority_queue<Bus, std::vector<Bus>, BusComparator> pq;

    pq.push(Bus{start, 0});
    while (pq.empty() == false)
    {
        int current_city = pq.top().v;
        int current_cost = pq.top().w;
        pq.pop();

        if (current_cost > dist[current_city]) continue;

        for (const Bus& bus : graph[current_city])
        {
            int destination = bus.v;
            int cost = bus.w;

            if (current_cost + cost < dist[destination])
            {
                dist[destination] = current_cost + cost;
                parent[destination] = current_city;
                pq.push(Bus{destination, dist[destination]});
            }
        }
    }

    return dist[destination];
}

void PrintPath(const std::vector<int>& parent, const int start, const int destination)
{
    std::vector<int> path;
    // Note: -1 is start point in parent
    // find previous city with starting at destination
    for (int city = destination; city != -1; city = parent[city])
    {
        path.push_back(city);
    }

    // print count of path
    std::cout << path.size() << '\n';

    // print in reverse
    for (auto city = std::prev(path.end()); city != path.begin(); city = std::prev(city))
    {
        std::cout << *city + 1 << ' ';
    }
    std::cout << *path.begin() + 1 << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n; // [1, 1000] cities
    int m; // [1, 100'000] buses
    int start_city;
    int destination_city;

    std::cin >> n >> m;

    // direction graph with weight

    Graph bus(n, std::vector<Bus>());
    for (int i=0; i<m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;

        bus[u-1].push_back(Bus{v-1, w});
    }
    std::cin >> start_city >> destination_city;

    std::vector<int> parent;
    auto min_cost = dijkstra(bus, start_city - 1, destination_city - 1, parent);
    std::cout << min_cost << '\n';
    PrintPath(parent, start_city - 1, destination_city - 1);

    return 0;
}
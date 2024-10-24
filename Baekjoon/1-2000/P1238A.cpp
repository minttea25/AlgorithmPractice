// 파티
// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Path
{
public:
    int d;
    int w;

    bool operator<(const Path& other) const
    {
        return w > other.w;
    }
};

// struct PathComp
// {
//     bool operator()(const Path& lhs, const Path& rhs)
//     {
//         return lhs.w > rhs.w;
//     }
// };

using Graph = std::vector<std::vector<Path>>;

void dijkstra(const int start, const Graph& graph, std::vector<int>& output)
{
    output.assign(graph.size(), std::numeric_limits<int>::max());
    output[start] = 0;

    std::priority_queue<Path> pq;

    pq.push({start, 0});
    while (pq.empty() == false)
    {
        auto current = pq.top();
        pq.pop();

        for (const Path& p : graph[current.d])
        {
            if (current.w + p.w < output[p.d])
            {
                output[p.d] = current.w + p.w;
                pq.push({p.d, current.w + p.w});
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int x;
    std:: cin >> x;
    x--;

    // house -> x : reverse path / x -> house dijkstra
    // x -> house : house -> dijkstra

    Graph graph(n, std::vector<Path>());
    Graph rev_graph(n, std::vector<Path>());
    for (int i=0; i<m; ++i)
    {
        int s, d, w;
        std::cin >> s >> d >> w;
        d--;
        s--;
        graph[s].push_back({d, w});
        rev_graph[d].push_back({s, w});
    }
    
    std::vector<int> house_to_x;
    dijkstra(x, rev_graph, house_to_x);
    std::vector<int> x_to_house;
    dijkstra(x, graph, x_to_house);

    int mx = 0;
    for (int i=0; i<house_to_x.size(); ++i)
    {
        mx = std::max(house_to_x[i] + x_to_house[i], mx);
    }

    std::cout << mx << std::endl;

    return 0;
}
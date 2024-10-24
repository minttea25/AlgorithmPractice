#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Node
{
public:
    int v; // vertex
    int w; // weight
};

struct NodeComparatorGreater
{
    bool operator()(const Node& lhs, const Node& rhs)
    {
        return lhs.w > rhs.w;
    }
};

struct NodeComparatorLess
{
    bool operator()(const Node& lhs, const Node& rhs)
    {
        return lhs.w < rhs.w;
    }
};

using Graph = std::vector<std::vector<Node>>;
constexpr int START_NODE_MARK = -1;
constexpr int DEFAULT = std::numeric_limits<int>::max();

int Dijkstra(const Graph& graph, const int start, const int destination, std::vector<int>& parent)
{
    const int size = graph.size(); // number of nodes
    parent.assign(size, START_NODE_MARK);
    std::vector<int> dist(size, DEFAULT);

    dist[start] = 0;

    std::priority_queue<Node, std::vector<Node>, NodeComparatorLess> pq;

    // set dist of between start - start 0
    pq.push(Node{start, 0});
    while (pq.empty() == false)
    {
        int current_node = pq.top().v;
        int current_cost = pq.top().w;

        // Need not to compare if the current_cost is bigger than calculated of current_node
        if (current_cost > dist[current_node]) continue;

        for (const Node& node : graph[current_node])
        {
            int destination = node.v;
            int cost = node.w;

            if (current_cost + cost < dist[destination])
            {
                dist[destination] = current_cost + cost;
                parent[destination] = current_node; // for tracing visited path
                pq.push(Node{destination, dist[destination]});
            }
        }
    }

    return dist[destination];
}

void TracingVisited(const std::vector<int>& parent, const int start, const int destination)
{
    std::vector<int> reverse_path;
    // Note: START_NODE_MARK is the start node in parent
    // Find previous node continuously until the start node appears.
    for (auto node = destination; node != START_NODE_MARK; node = parent[node])
    {
        reverse_path.push_back(node);
    }

    // Check the visited path (without start node)
    for (auto node = std::prev(reverse_path.end()); node != reverse_path.begin(); node = std::prev(node))
    {
        // Do something with node (*node)
    }
    // Do something with start node (*reverse_path.begin())

    // You can use for iterator simply
    for (int i=reverse_path.size()-1; i>=0; --i)
    {
        // Do something with reverse_path[i]
    }
}

int main()
{

    return 0;
}
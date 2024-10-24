// 연결 요소의 개수
// https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <stack>

using Graph = std::vector<std::vector<int>>;

void dfs(const Graph& graph, std::vector<bool>& visited, const int start)
{
    std::stack<int> s;

    s.push(start);
    visited[start] = true;
    while (s.empty() == false)
    {
        auto top = s.top();
        s.pop();

        for (const auto& v : graph[top])
        {
            if (visited[v] == false) 
            {
                s.push(v);
                visited[v] = true;
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

    Graph graph(n, std::vector<int>());
    for (int i=0; i<m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    std::vector<bool> visited(n, false);
    // use dfs - search all
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        if (visited[i] == false) 
        {
            dfs(graph, visited, i);
            count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}
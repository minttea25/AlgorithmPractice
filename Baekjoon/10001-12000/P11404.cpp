// 플로이드
// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <vector>

constexpr int DEFAULT = 99999999;

using Graph = std::vector<std::vector<int>>;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Graph graph(n, std::vector<int>(n, DEFAULT));
    for (int i=0; i<m; ++i)
    {
        int s, e, w;
        std::cin >> s >> e >> w;
        graph[s-1][e-1] = std::min(w, graph[s-1][e-1]);
    }
    for (int i=0; i<n; ++i)
    {
        graph[i][i] = 0;
    }

    auto dist = graph; // copy
    
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<n; ++ii)
        {
            for (int iii=0; iii<n; ++iii)
            {
                if (dist[ii][i] != DEFAULT
                    && dist[i][iii] != DEFAULT)
                    {
                        dist[ii][iii] = std::min(dist[ii][i] + dist[i][iii], dist[ii][iii]);
                    }
            }
        }
    }

    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<n; ++ii)
        {
            if (dist[i][ii] == DEFAULT) std::cout << 0 << ' ';
            else std::cout << dist[i][ii] << ' ';
        }
        std::cout << '\n';
    }


    return 0;
}
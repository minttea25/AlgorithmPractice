// 특정한 경로
// https://www.acmicpc.net/problem/1504

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

constexpr int DEFAULT = INT32_MAX;

pair<int, int> dijkstra(const vector<vector<int>>& graph, const int start, const int des1, const int des2)
{
    const int v = graph.size();
    vector<int> dist(v, DEFAULT);

    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int i=1; i<v; ++i)
        {
            const int weight = graph[u][i];

            if (weight == 0) continue;

            if (dist[u] != DEFAULT && dist[u] + weight < dist[i])
            {
                dist[i] = dist[u] + weight;
                pq.push({dist[i], i});
            }
        }
    }

    return {dist[des1], dist[des2]};
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));

    for (int i=0; i<e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a][b] = c;;
        graph[b][a] = c;
    }

    int u, v;
    cin >> u >> v;

    auto U = dijkstra(graph, u, v, n);
    auto V = dijkstra(graph, v, u, n);
    auto S = dijkstra(graph, 1, u, v);

    int s_u_v_n = (S.first != DEFAULT && U.first != DEFAULT && V.second != DEFAULT) ? S.first + U.first + V.second : DEFAULT;
    int s_v_u_n = (S.second != DEFAULT && V.first != DEFAULT && U.second != DEFAULT) ? S.second + V.first + U.second : DEFAULT;

    int ans = min(s_u_v_n, s_v_u_n);

    if (ans == DEFAULT) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
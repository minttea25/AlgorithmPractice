// 파티
// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using pii = pair<int, int>;

constexpr int MAX_DIST = 999999999;

vector<int> dijkstra(const int start, const vector<vector<pii>>& path)
{
    const int n = path.size();
    vector<int> dist(n, MAX_DIST);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});
    while (pq.empty() == false)
    {
        auto p = pq.top();
        pq.pop();

        for (auto next : path[p.second])
        {
            int d = dist[p.second] + next.second;

            if (d < dist[next.first])
            {
                dist[next.first] = d;
                pq.push({next.second, next.first});
            }
        }
    }

    return dist;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pii>> path(n, vector<pii>());
    vector<vector<pii>> reverse_path(n, vector<pii>());

    for (int i=0; i<m; ++i)
    {
        int begin, end, w;
        cin >> begin >> end >> w;

        path[begin - 1].push_back({end - 1, w});
        reverse_path[end - 1].push_back({begin - 1, w});
    }

    auto go = dijkstra(x - 1, path);
    auto reverse_go = dijkstra(x - 1, reverse_path);

    int ans = -1;
    for (int i=0; i<n; ++i)
    {
        int sum = go[i] + reverse_go[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
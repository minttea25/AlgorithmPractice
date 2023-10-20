// 서강그라운드
// https://www.acmicpc.net/problem/14938

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using PATH = pair<int, int>; // weight, des

int dijkstra(const int start, const vector<vector<PATH>>& map, const int n, const int range, const vector<int>& areas)
{
    priority_queue<PATH, vector<PATH>, greater<PATH>> pq;
    vector<int> dist(n, 99999999);
    dist[start] = 0;
    
    pq.push({0, start});

    while (pq.empty() == false)
    {
        int cur = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        for(const PATH& path : map[cur])
        {
            int next = path.second;
            int ww = path.first;

            if (w + ww <= range && w + ww < dist[next])
            {
                dist[next] = w + ww;
                pq.push({dist[next], next});
            }
        }
    }

    int items = 0;
    for(int i=0; i<dist.size(); ++i)
    {
        if (dist[i] <= range) items += areas[i];
    }
    return items;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 지역의 개수
    int m; // 수색 범위
    int r; // 길의 개수

    cin >> n >> m >> r;

    vector<int> areas;
    for(int i=0; i<n; ++i)
    {
        int t;
        cin >> t;
        areas.push_back(t);
    }

    // 양방향
    vector<vector<PATH>> map(n, vector<PATH>());
    for(int i=0; i<r; ++i)
    {
        int a, b, l;
        cin >> a >> b >> l;
        map[a-1].push_back({l, b-1});
        map[b-1].push_back({l, a-1});
    }

    int ans = 0;
    for(int i=0; i<n; ++i)
    {
        ans = max(ans, dijkstra(i, map, n, m, areas));
    }

    cout << ans << '\n';

    return 0;
}
// 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

constexpr int MAX = 100;

int dijkstra(const int start, vector<vector<bool>>& relations, const int n)
{
    vector<int> dist(n, 99999);

    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int fri = pq.top().second;
        pq.pop();

        if (d > dist[fri]) continue;

        for(int i=0; i<n; ++i)
        {
            if (relations[fri][i] == true)
            {
                const int next_friend = i;
                const int next_dist = d + 1;
                if (next_dist < dist[next_friend]) 
                {
                    dist[next_friend] = next_dist;
                    pq.push({next_dist, next_friend});
                }
            }
        }
    }

    int sum = 0;
    for(const int& d : dist)
    {
        sum += d;
    }
    return sum;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n; // 유저 수
    int m; // 관계 수

    cin >> n >> m;

    vector<vector<bool>> relations(MAX, vector<bool>(n, false));
    vector<int> friends(n, 99999);

    int ans = -1;
    for(int i=0; i<m; ++i)
    {
        int a, b;
        cin >> a >> b;

        // 양뱡향
        relations[a-1][b-1] = true;
        relations[b-1][a-1] = true;

        int mn = 99999;
        for(int ii=0; ii<n; ++ii)
        {
            const int value = dijkstra(ii, relations, n);
            if (mn > value)
            {
                mn = value;
                ans = ii + 1;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
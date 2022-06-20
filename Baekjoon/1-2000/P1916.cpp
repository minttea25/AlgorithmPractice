// 최소비용 구하기
// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
// #include <bits/stdc++.h>

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

using namespace std;

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

class CMP {
    public:
    bool operator() (const iip &e1, const iip &e2) const {
        return e1.second > e2.second;
    }
};

constexpr int DEFAULT = 200000000;

vector<iip> g[1001];
int dist[1001];
int N, M;
int S, E;
priority_queue<iip, vector<iip>, CMP> q;

void dijkstra(int n) {
    q.push({n, 0});
    dist[n] = 0;

    while(!q.empty()) {
        int p = q.top().first;
        int w = q.top().second;
        q.pop();

        if (dist[p] < w) continue;

        for (iip v : g[p]) {
            if (dist[v.first] > dist[p] + v.second) {
                dist[v.first] = dist[p] + v.second;
                q.push({v.first, dist[v.first]});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    fill_n(dist, 1001, DEFAULT);

    int u, v, w;
    cin >> N >> M;
    
    FOR(i, 0, M) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    cin >> S >> E;

    dijkstra(S);

    cout << dist[E] << endl;

    return 0;
}
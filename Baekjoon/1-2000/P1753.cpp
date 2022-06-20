// 최단경로
// https://www.acmicpc.net/problem/1753

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

vector<iip> g[20001];
int dist[20001];
priority_queue<iip, vector<iip>, CMP> q;
int V, E, K;

void dijkstra(int n) {
    q.push({n, 0});
    dist[n] = 0;

    while(!q.empty()) {
        int p = q.top().first;
        int w = q.top().second;
        q.pop();

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

    fill_n(dist, 20001, DEFAULT);

    int v, w, u;

    cin >> V >> E >> K;

    FOR(i, 0, E) {
        cin >> u >> v >> w;

        g[u].push_back({v, w});
    }

    dijkstra(K);

    FOR_(i, 1, V) {
        if (dist[i] == DEFAULT) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
// 특정 거리의 도시 찾기
// https://www.acmicpc.net/problem/18352

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost all header files for algorithm practice.
// It is not a standard library header for C++, but a valid header only with the gcc compiler.
// #include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

#define DEFAULT 2000000001

int N, M, K, X;
iv graph[300001];

int dist[300001];
priority_queue<int, iv, greater<int>> q;

void dijkstra(int nd) {
    dist[nd] = 0;
    q.push(nd);

    while(!q.empty()) {
        int now = q.top();
        q.pop();

        for (int next : graph[now]) {
            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K >> X;

    fill_n(dist, N+1,  DEFAULT);

    int a, b;
    FOR(i, 0, M) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dijkstra(X);

    bool empty = true;
    FOR_(i, 1, N) {
        if (dist[i] == K) {
            empty = false;
            cout << i << endl;
        }
    }
    if (empty) cout << -1 << endl;

    return 0;
}
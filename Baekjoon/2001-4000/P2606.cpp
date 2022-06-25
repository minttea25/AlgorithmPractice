// 바이러스
// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost all header files for algorithm practice.
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

bool visited[101];
iv graph[101];
int N, M;
int cnt;

void bfs(int nd) {
    queue<int> q;
    visited[nd] = true;
    q.push(nd);

    while(!q.empty()) {
        int t = q.front();
        q.pop();

        for (int b : graph[t]) {
            if (!visited[b]) {
                visited[b] = true;
                cnt++;
                q.push(b);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    int a, b; // a - b
    FOR(i, 0, M) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    cout << cnt << endl;

    return 0;
}
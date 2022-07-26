// ABCDE
// https://www.acmicpc.net/problem/13023

#include <iostream>
#include <vector>
#include <algorithm>

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

#define MAX 2000+1

int N, M;
vector<int> adj[MAX];
bool ans;
bool visited[MAX] = {0, };

void checkRelationShip(int node, int pnode, int depth) {
    visited[node] = true;

    if (depth == 4) {
        cout << 1 << endl;
        exit(0);
    }

    for (int nd : adj[node]) {
        if(pnode != nd && !visited[nd]) {
            checkRelationShip(nd, node, depth+1);
        }
    }
    visited[node] = false;
}

int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b;

    cin >> N >> M;

    for (int i=0; i<M; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<N; i++) {
        checkRelationShip(i, -1, 0);

        if (ans) break;
    }

    cout << ans << endl;

    return 0;
}
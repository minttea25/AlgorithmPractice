// 촌수계산
// https://www.acmicpc.net/problem/2644

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

constexpr int MAX = 100+1;

int N, A, B, M;
iv graph[MAX];
int visited[MAX];
bool found = false;
int rel;

void dfs(int nd, int lv) {
    visited[nd] = true;

    if (nd == B) {
        found = true;
        rel = lv;
        return;
    }

    for(int n : graph[nd]) {
        if (found) return;
        if (!visited[n]) {
            dfs(n, lv+1);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> A >> B >> M;

    int a, b;
    FOR(i, 0, M) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(A, 0);

    if (!found) {
        cout << -1  << endl;
    }
    else {
        cout << rel << endl;
    }

    return 0;
}
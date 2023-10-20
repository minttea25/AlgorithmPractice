// 효율적인 해킹
// https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

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

int N, M;
iv com[10001];
bool visited[10001] = {false, };
int hackable[10001] = {0, };

int DFS(int n) {
    memset(visited, false, sizeof(visited));
    stack<int> s;
    int cnt = 0;

    s.push(n);
    cnt++;
    while(s.empty() == false) {
        int p = s.top();
        s.pop();

        if (visited[p] == true) continue;

        visited[p] = true;
        cnt++;
        for(int v : com[p]) {
            if (visited[v] == false) {
                s.push(v);
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    FOR(i, 0, M) {
        int a, b;
        cin >> a >> b;
        com[b].push_back(a);
    }

    int mx = -1;
    FOR_(i, 1, N) {
        hackable[i] = DFS(i);
        cout << "s: " << i << " cnt: " << hackable[i] << endl;
        if (hackable[i] > mx) {
            mx = hackable[i];
        }
    }

    iv ans;

    FOR_(i, 1, N) {
        if (hackable[i] == mx) ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    for(int a : ans) {
        cout << a << ' ';
    }

    return 0;
}
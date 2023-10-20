// 점프 점프
// https://www.acmicpc.net/problem/11060

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

int N;
int meiro[1001];
bool visited[1001] = {false, };

int bfs(int start) {
    if (start == N) return 0;

    queue<iip> q;
    q.push({start, 0});

    while(q.empty() == false) {
        iip p = q.front();
        q.pop();

        FOR_(i, 1, meiro[p.first]) {
            int c = p.first+i;
            if (visited[c] == false && c < N) {
                cout << "added: " << c << endl;
                visited[c] = true;
                q.push({c, p.second+1});
            }
            else if (c == N) {
                return p.second+1;
            }
        }
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    FOR_(i, 1, N) {
        cin >> meiro[i];
    }

    cout << bfs(1) << endl;

    return 0;
}
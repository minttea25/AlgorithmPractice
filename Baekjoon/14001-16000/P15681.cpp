// 트리와 쿼리
// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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

vector<iv> path(100001);
int ans[100001];
bool visited[100001] = {false, };
int N, R, Q;
iv q;

int DFS(int start) {
    int cnt = 1;
    visited[start] = true;

    for(auto v : path[start]) {
        if (visited[v] == false) {
            int t = DFS(v);
            ans[v] = t;
            cnt += t;
        }
    }
    return cnt;
}   

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> R >> Q;

    FOR(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    FOR(i, 0, Q) {
        int a;
        cin >> a;
        q.push_back(a);
    }

    ans[R] = DFS(R);

    for(auto qq : q) {
        cout << ans[qq] << endl;
    }

    return 0;
}
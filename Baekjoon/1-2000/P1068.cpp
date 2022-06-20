// 트리
// https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>
#include <algorithm>

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

constexpr int MAX = 50+1;

iv nodes[MAX];
int N;
int removed;
int root;
int leaves;

void dfs(int nd, int pd) {
    if (nd != removed && nodes[nd].size() == 0) {
        leaves++;
        return;
    }

    // if the parent node turn to leaf node when nd is removed.
    if (pd != -1 && nd == removed && nodes[pd].size() == 1) {
        leaves++;
        return;
    }

    for (int node : nodes[nd]) {
        dfs(node, nd);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int t;

    cin >> N;

    FOR(i, 0, N) {
        cin >> t;
        if (t != -1) {
            nodes[t].push_back(i);
        }
        else {
            root = i;
        }
    }
    if (N!=1) {
        cin >> removed;
    }
    nodes[removed].clear();

    if (root == removed) {
        leaves = 0;
    }
    else {
        dfs(root, -1);
    }

    cout << leaves << endl;

    return 0;
}
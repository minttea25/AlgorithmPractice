// DFS와 BFS
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

int N, M, V;
vector<iv> vertex(1001);
bool dfs_visited[1001] = {false, };
bool bfs_visited[1001] = {false, };
iv v_dfs;
iv v_bfs;

void DFS() {
    stack<int> stack;
    
    stack.push(V);
    while(stack.empty() == false) {
        int pop = stack.top();
        stack.pop();

        if (dfs_visited[pop] == true) continue;
        
        v_dfs.push_back(pop);
        dfs_visited[pop] = true;

        for (int v : vertex[pop]) {
            if (dfs_visited[v] == false) {
                stack.push(v);
            }
        }
    }
}

void BFS() {
    queue<int> q;

    q.push(V);
    bfs_visited[V] = true;
    v_bfs.push_back(V);

    while(q.empty() == false) {
        int n = q.front();
        q.pop();
        
        for (int v : vertex[n]) {
            if (bfs_visited[v] == false) {
                q.push(v);
                bfs_visited[v] = true;
                v_bfs.push_back(v);
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> V;
    FOR(i, 0, M){
        int a, b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    FOR(i, 1, N+1) {
        sort(vertex[i].begin(), vertex[i].end());
    }

    BFS();

    FOR(i, 1, N+1) {
        sort(vertex[i].begin(), vertex[i].end(), greater<int>());
    }
    DFS();

    // print dfs
    FOR(i, 0, v_dfs.size()) {
        cout << v_dfs[i] << ' ';
    }
    cout << endl;

    // print BFS
    FOR(i, 0, v_bfs.size()) {
        cout << v_bfs[i] << ' ';
    }

    return 0;
}
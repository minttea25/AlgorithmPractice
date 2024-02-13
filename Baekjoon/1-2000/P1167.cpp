// 트리의 지름
// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
using namespace std;

using E = pair<int ,int>;

constexpr int MAX = 1'000'000'000;

/// @brief Return first {farest node, distance} starting at start with DFS
/// @param tree 
/// @param start 
/// @return 
pair<int, int> dfs(const vector<vector<E>>& tree, const int start)
{
    const int n = tree.size();
    int mx = 0;
    vector<int> dist(n, MAX);
    dist[start] = 0;
    stack<int> s;
    int farest = -1;
    s.push(start);

    while (s.empty() == false)
    {
        auto p = s.top();
        s.pop();

        for(auto v : tree[p])
        {
            if (dist[v.first] != MAX) continue;

            // Note : no cycles
            dist[v.first] = dist[p] + v.second;
            s.push(v.first);

            if (dist[v.first] > mx) 
            {
                mx = dist[v.first];
                farest = v.first;
            }
        }
    }

    return {farest, mx};
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<E>> tree(n);

    for(int i=0; i<n; ++i)
    {
        int a, b, w;
        cin >> a;
        while (true)
        {
            cin >> b;
            if (b == -1) break;
            cin >> w;
            tree[a-1].push_back({b-1, w});
            tree[b-1].push_back({a-1, w});
        }
    }
    
    auto root = dfs(tree, 0).first;
    auto ans = dfs(tree, root);
    cout << ans.second << endl;

    return 0;
}
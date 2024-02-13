// 트리의 순회
// https://www.acmicpc.net/problem/2263

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define endl '\n'
using namespace std;

using pii = pair<int, int>;
using piiii = pair<pii, pii>;

constexpr int NONE = 0;

piiii devide_subtree_by_root(const vector<int>& in_order, const int left, const int right, const int root)
{
    if (in_order[left] == root) return { {NONE+1, NONE}, {left+1, right} };
    else if (in_order[right] == root) return { {left, right-1}, {NONE+1, NONE} };

    // O(n)
    // find index of root-node in in-order
    int r;
    for(int i=left+1; i<right; ++i)
    {
        if (in_order[i] == root) r = i;
    }
    return { {left, r-1}, {r+1, right} };

}

piiii devide_subtree_by_count(const vector<int>& post_order, const int left, const int right, int right_count)
{
    // right_count is not 0

    // left tree: [left, right - count]
    // right tree: [right - count + 1, right]
    return { {left, right - right_count}, {right - right_count + 1, right} };
}

void loop(const vector<int>& in_order, const vector<int>& post_order, const pii i_range, const pii p_range, vector<vector<int>>& tree)
{
    int root = post_order[p_range.second];
    auto devided = devide_subtree_by_root(in_order, i_range.first, i_range.second, root);

    int left_count = devided.first.second - devided.first.first + 1;
    int right_count = devided.second.second - devided.second.first + 1;

    if (left_count == NONE && right_count == NONE)
    {
        return;
    }
    // no left sub-tree of root
    else if (left_count == NONE)
    {
        // only one sub-tree
        tree[root].push_back(post_order[p_range.second-1]);

        // do right sub-tree
        loop(in_order, post_order, {i_range.first+1, i_range.second}, {p_range.first, p_range.second-1}, tree);
    }
    // no right sub-tree of root
    else if (right_count == NONE)
    {
        // only one sub-tree
        tree[root].push_back(post_order[p_range.second-1]);

        // do left sub-tree
        loop(in_order, post_order, {i_range.first, i_range.second-1}, {p_range.first, p_range.second-1}, tree);
    }
    else
    {
        auto devided2 = devide_subtree_by_count(post_order, p_range.first, p_range.second - 1, right_count);

        int left_count2 = devided2.first.second - devided2.first.first + 1;
        int right_count2 = devided2.second.second - devided2.second.first + 1;

        tree[root].push_back(post_order[devided2.first.second]);
        tree[root].push_back(post_order[devided2.second.second]);
        // 2 cases
        if (left_count2 != 1) loop(in_order, post_order, devided.first, devided2.first, tree);
        if (right_count2 != 1) loop(in_order, post_order, devided.second, devided2.second, tree);
    }
}

vector<int> pre_order(const vector<vector<int>>& tree, const int root)
{
    vector<int> visited;

    stack<int> s;
    s.push(root);

    while (s.empty() == false)
    {
        auto p = s.top();
        s.pop();

        visited.push_back(p);

        // reverse why? 위에서 우측정렬로 트리를 만들었기 때문, 출력은 좌측부터...
        for(int i=0; i<tree[p].size(); ++i)
        {
            s.push(tree[p][tree[p].size() - i - 1]);
        }
    }
    return visited;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> in_order;
    vector<int> post_order;

    int n;
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        int input;
        cin >> input;
        in_order.push_back(input-1);
    }
    for (int i=0; i<n; ++i)
    {
        int input;
        cin >> input;
        post_order.push_back(input-1);
    }

    vector<vector<int>> tree(n);
    loop(in_order, post_order, {0, n-1}, {0, n-1}, tree);

    auto ans = pre_order(tree, post_order[n-1]);

    for (auto v : ans)
    {
        cout << v + 1 << ' ';
    }
    cout << endl;

    return 0;
}
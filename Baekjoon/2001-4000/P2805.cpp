// 나무 자르기
// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using uint = unsigned int;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; // number of trees [1, 1'000'000]
    uint m; // the length to bring [1, 2'000'000'000]

    cin >> n >> m;

    vector<uint> trees;
    for (int i=0; i<n; ++i)
    {
        uint t;
        cin >> t;
        trees.push_back(t);
    }

    sort(trees.begin(), trees.end(), greater<uint>());
    trees.push_back(0);

    vector<ll> acc;
    acc.push_back(0);

    uint prev_height = trees[0];
    for (int i=1; i<n+1; ++i) 
    {
        if (acc.back() > m) break;

        uint h = prev_height - trees[i];
        acc.push_back(i * (ll)h + acc.back());
        prev_height = trees[i];
    }

    auto it = lower_bound(acc.begin(), acc.end(), m);
    while(true)
    {
        if (*it == *prev(it)) it--;
        else break;
    }
    int idx = distance(acc.begin(), it);

    if (*it == m) 
    {
        cout << trees[idx] << endl;
    }
    else
    {
        ll rest = *it - m;
        ll height = trees[idx];
        ll width = idx;
        ll additional_height = rest/width;
        cout << trees[idx] + additional_height << endl;
    }

    return 0;
}
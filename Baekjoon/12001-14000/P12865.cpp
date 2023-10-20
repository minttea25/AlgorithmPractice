// 평범한 배낭
// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>

using namespace std;

struct item
{
public:
    item(int weight_, int value_) : weight(weight_), value(value_) {}
public:
    int weight, value;
};

/// @brief capacity의 용량이 남았을 때 item을 넣거나 넣지 않았을 때의 value 최대 값 계산
/// @param capacity 남은 가방 용량
/// @param n_item n번째 item
/// @param items 아이템 정보
/// @param weights memory for memoization (n_item 이후)
/// @return capacity 용량이 남았을 때의 value 최댓값 반환
int pack(const int capacity, const int n_item, const vector<item>& items, vector<vector<int>>& weights)
{
    if (n_item == items.size()) return 0;

    int& ret = weights[capacity][n_item];
    if (ret != 0) return ret;

    // item을 넣지 않을 경우
    ret = pack(capacity, n_item+1, items, weights);

    if (capacity >= items[n_item].weight) 
    {
        // item을 넣을 경우
        ret = max(ret, pack(capacity - items[n_item].weight, n_item+1, items, weights) + items[n_item].value);
    }

    return ret;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<item> items;
    vector<vector<int>> weights(k+1);
    for(int i=0; i<k+1; ++i) weights[i] = vector<int>(n);

    for(int i=0; i<n; ++i) 
    {
        int w, v;
        cin >> w >> v;

        items.push_back(item(w, v));
    }

    int ans = pack(k, 0, items, weights);
    cout << ans << '\n';

    return 0;
}
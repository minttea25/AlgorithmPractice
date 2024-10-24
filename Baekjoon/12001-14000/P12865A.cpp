// 평범한 배낭
// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>

constexpr int DEFAULT = -99999999;

struct Item
{
public:
    int w;
    int v;
};

int Pack(const std::vector<Item>& bag, const int capacity, int item_n, std::vector<std::vector<int>>& ans)
{
    if (item_n >= bag.size()) return 0;

    int& ret = ans[capacity][item_n];
    if (ret != DEFAULT) return ret;

    // ireru (with check the capacity)
    if (capacity - bag[item_n].w >= 0)
        ret = std::max(ret, Pack(bag, capacity - bag[item_n].w, item_n+1, ans) + bag[item_n].v);

    // irenai
    ret = std::max(ret, Pack(bag, capacity, item_n+1, ans));

    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n; // [1, 100]
    int k; // [1, 100000]

    std::cin >> n >> k;

    std::vector<Item> bag;
    for (int i=0; i<n; ++i)
    {
        int w, v;
        std::cin >> w >> v;
        bag.push_back(Item{w, v});
    }

    std::vector<std::vector<int>> ans(k+1, std::vector<int>(n, DEFAULT));

    auto value = Pack(bag, k, 0, ans);
    std::cout << value << std::endl;

    return 0;
}
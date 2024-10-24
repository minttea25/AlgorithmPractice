// 피보나치 함수
// https://www.acmicpc.net/problem/1003

#include <iostream>
#include <vector>

using pii = std::pair<int, int>;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<pii> v;

    //base
    v.push_back({1, 0}); // 0
    v.push_back({0, 1}); // 1
    for (int i=2; i<=40; ++i)
    {
        v.push_back({v[i-1].first + v[i-2].first, v[i-1].second+ v[i-2].second});
    }

    int t;
    std::cin >> t;

    while (t > 0)
    {
        int tc;
        std::cin >> tc;

        std::cout << v[tc].first << ' ' << v[tc].second << '\n';

        t--;
    }

    return 0;
}
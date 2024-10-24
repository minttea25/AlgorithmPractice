// 동전 0
// https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>

constexpr const int TYPES = 10;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int coins[TYPES] = {0, };
    for (int i=0; i<n; ++i)
    {
        std::cin >> coins[i];
    }
    std::cout << std::endl;


    int ans = 0;
    for (int i=n-1; i>=0; --i)
    {
        int cnt = k / coins[i];
        ans += cnt;
        k %= coins[i];
    }

    std::cout << ans << '\n';

    return 0 ;
}
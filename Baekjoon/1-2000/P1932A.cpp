// 정수 삼각형
// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <vector>

using Triangle = std::vector<std::vector<int>>;

constexpr int DEFAULT = -1;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    Triangle t(n, std::vector<int>(n, DEFAULT));
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<i+1; ++ii)
        {
            int v;
            std::cin >> v;
            t[i][ii] = v;
        }
    }

    for (int i=1; i<n; ++i)
    {
        for (int ii=0; ii<i+1; ++ii)
        {
            auto left = ((i - 1 < 0 || ii - 1 < 0) ? DEFAULT : t[i-1][ii-1]);
            auto right = (i - 1 < 0 ? DEFAULT : t[i-1][ii]);
            t[i][ii] += std::max(left, right);
        }
    }

    int ans = -1;
    for (int i=0; i<n; ++i)
    {
        ans = std::max(ans, t[n-1][i]);
    }

    std::cout << ans << std::endl;

    return 0;
}
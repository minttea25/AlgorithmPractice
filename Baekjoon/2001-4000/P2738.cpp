// 행렬 덧셈
// https://www.acmicpc.net/problem/2738

#include <iostream>

constexpr int MAX = 100;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int16_t matrix[MAX][MAX] = {{}};

    int n, m;
    std::cin >> n >> m;

    for (auto i=0; i<n; ++i)
    {
        for (auto j=0; j<m; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    for (auto i=0; i<n; ++i)
    {
        for (auto j=0; j<m; ++j)
        {
            int t;
            std::cin >> t;
            matrix[i][j] += t;
        }
    }

    // print matrix
    for (auto i=0; i<n; ++i)
    {
        for (auto j=0; j<m; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
// 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int psum[100001] = {0, };
    for (int i=1; i<=n; ++i)
    {
        int v;
        std::cin >> v;

        psum[i] = psum[i-1] + v;
    }

    while (m > 0)
    {
        int a, b;
        std::cin >> a >> b;

        std::cout << psum[b] - psum[a-1] << '\n';

        m--;
    }

    return 0;
}
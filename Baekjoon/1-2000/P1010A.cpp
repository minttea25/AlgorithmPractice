// 다리 놓기
// https://www.acmicpc.net/problem/1010

#define NOMINMAX // for windows

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using ull = unsigned long long;
using ushort = uint16_t;

constexpr int MAX = 30;
constexpr int FACT_MAX = (MAX % 2 == 0 ? (MAX / 2 + 1) : (MAX / 2));

template<ushort N>
struct fact
{
    static const ull value = N * fact<N-1>::value;
};

template<>
struct fact<1>
{
    static const ull value = 1;
};

constexpr std::array<ull, FACT_MAX> generate_factorials() {
    std::array<ull, FACT_MAX> factorials = 
    {
        1ull,
        fact<1>::value,
        fact<2>::value,
        fact<3>::value,
        fact<4>::value,
        fact<5>::value,
        fact<6>::value,
        fact<7>::value,
        fact<8>::value,
        fact<9>::value,
        fact<10>::value,
        fact<11>::value,
        fact<12>::value,
        fact<13>::value,
        fact<14>::value,
        fact<15>::value,
    };

    return factorials;
}

constexpr ull multiply(const ushort n, const ushort count)
{
    if (count == 0) return 1;
    return n * multiply(n - 1, count - 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto factorials = generate_factorials();

    int tc;
    std::cin >> tc;

    while (tc > 0)
    {
        ushort n, m;
        std::cin >> n >> m;

        // calculate: mCn
        n = std::min(n, (ushort)(m-n));

        auto a = multiply(m, n);
        auto b = factorials[n];

        std::cout << a / b << '\n';

        tc--;
    }

    return 0;
}
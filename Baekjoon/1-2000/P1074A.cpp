// Z
// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <vector>

// cleaned up by ChatGpt
constexpr int CalcQuadrant(const int n, const int r, const int c) {
    if (n == 0) return 0;

    // 현재 단계에서 사분면 크기
    const unsigned long long t = 1ull << (n - 1);

    // 사분면 결정 (1 | 2) (3 | 4)
    int q = (r >= t ? 2 : 0) + (c >= t ? 1 : 0) + 1;

    // 새로운 좌표 (nr, nc)
    int nr = (r >= t) ? r - t : r;
    int nc = (c >= t) ? c - t : c;

    // 현재 사분면의 시작 값 + 재귀 호출을 통한 나머지 값
    return (q - 1) * t * t + CalcQuadrant(n - 1, nr, nc);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, r, c;
    std::cin >> n >> r >> c;

    std::cout << CalcQuadrant(n, r, c) << std::endl;

    return 0;
}
// Four Squares
// https://www.acmicpc.net/problem/17626

#include <iostream>
#include <cmath>

constexpr int MAX_COUNT = 4;

constexpr static int Find(int* arr, const int n)
{
    int& ret = arr[n];
    if (n == 0 || ret != 0) return ret;
    else if (sqrt(n) - (int)(sqrt(n)) == 0) return ret = 1;
    else
    {
        ret = MAX_COUNT+1;
        int s = static_cast<int>(floor(sqrt(n)));
        for (int i = s; i > 0; --i)
        {
            ret = std::min(1 + Find(arr, n - i*i), ret);
            if (ret == 2) break;
        }
    }
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    int* arr = new int[n+1];
    for (int i=0; i<n+1; ++i) arr[i] = 0;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    auto ans = Find(arr, n);

    std::cout <<ans << '\n';

    delete[] arr;

    return 0;
}
// 내려가기
// https://www.acmicpc.net/problem/2096

#include <iostream>
#include <vector>

constexpr int SIZE = 3;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    int temp1[SIZE] { 0, };
    int temp2[SIZE] { 0, };
    int mx_arr[SIZE] { 0, };
    int mn_arr[SIZE] { 0, };
    for (int i=0; i<n; ++i)
    {
        for (int ii=0; ii<SIZE; ++ii)
        {
            int v;
            std::cin >> v;

            if (ii==0) // left
            {
                mx_arr[ii] = v + std::max(temp1[ii], temp1[ii+1]);
                mn_arr[ii] = v + std::min(temp2[ii], temp2[ii+1]);
            }
            else if (ii==SIZE-1) // right
            {
                mx_arr[ii] = v + std::max(temp1[ii], temp1[ii-1]);
                mn_arr[ii] = v + std::min(temp2[ii], temp2[ii-1]);
            }
            else 
            {
                mx_arr[ii] = v + std::max(temp1[ii-1], std::max(temp1[ii], temp1[ii+1]));
                mn_arr[ii] = v + std::min(temp2[ii-1], std::min(temp2[ii], temp2[ii+1]));
            }

        }
        std::copy(mx_arr, mx_arr+SIZE, temp1);
        std::copy(mn_arr, mn_arr+SIZE, temp2);
    }

    int mx = -1;
    int mn = 9999999;
    for (int i=0; i<SIZE; ++i) 
    {
        mx = std::max(mx, temp1[i]);
        mn = std::min(mn, temp2[i]);
    }

    std::cout << mx << ' ' << mn << std::endl;

    return 0;
}
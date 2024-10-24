// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int map[101] = {0, };
    for (int i=0; i<n; ++i)
    {
        int start;
        int end;
        std::cin >> start >> end;
        map[start] = end; // to - from
    }
    for (int i=0; i<m; ++i)
    {
        int start;
        int end;
        std::cin >> start >> end;
        map[start] = -end;
    }

    // memoi
    int dice[101] = { 0, };
    std::fill_n(dice, 101, 99999999);
    dice[1] = 0;
    for (int i=2; i<=7; ++i) 
    {
        dice[i] = 1; // base
        // ladders
        if (map[i] > 0) dice[map[i]] = std::min(dice[i], dice[map[i]]);
    }

    for (int i=8; i<101; ++i)
    {
        int& mn = dice[i];
        for (int j=1; j<=6; ++j)
        {
            if (map[i-j] != 0) continue;
            int from = dice[i-j];
            mn = std::min(from + 1, mn);
        }
        // ladders
        if (map[i] > i) dice[map[i]] = std::min(mn, dice[map[i]]);
        // snake
        if (map[i] < 0) 
        {
            dice[-1 * map[i]] = std::min(mn, dice[-1 * map[i]]);
            map[i] *= -1;
            i = map[i];
        }
        
    }

    std::cout << dice[100] << '\n';

    return 0;
}
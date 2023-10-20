// 계단오르기
// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

using namespace std;

int cache[301][2];
int stairs[301];

int score(const int n, const bool continuous)
{
    if (n <= 0) return 0;

    int& ret = cache[n][continuous];
    if (ret != 0) return ret;

    if (continuous == false) ret = max(ret, stairs[n] + score(n-1, true));
    ret = max(ret, stairs[n] + score(n-2, false));

    return ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int stair;
    cin >> stair;

    for(int i=0; i<stair; ++i)
    {
        cin >> stairs[i+1];
    }

    cout << max(score(stair, false), score(stair, true)) << '\n';

    return 0;
}
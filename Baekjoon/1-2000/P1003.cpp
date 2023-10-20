// 피보나치 함수
// https://www.acmicpc.net/problem/1003

#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX = 40 + 1;

int cache[MAX][2];

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    // initialize cache
    //for(int i=0; i<41; ++i) cache[i][0] = cache[i][1] = -1;

    cache[0][0] = 1;
    cache[0][1] = 0;
    cache[1][0] = 0;
    cache[1][1] = 1;

    // pre-
    cache[2][0] = cache[2][1] = 1;

    for(int i=3; i<MAX; ++i)
    {
        cache[i][0] = cache[i-2][0] + cache[i-1][0];
        cache[i][1] = cache[i-2][1] + cache[i-1][1];
    }

    int tc;
    cin >> tc;

    for(int i=0; i<tc; ++i)
    {
        int input;
        cin >> input;

        cout << cache[input][0] << ' ' << cache[input][1] << '\n';
    }

    return 0;
}
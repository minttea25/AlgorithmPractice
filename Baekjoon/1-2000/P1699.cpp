// 제곱수의 합
// https://www.acmicpc.net/problem/1699

#include <iostream>
#include <cmath>

using namespace std;

int cache[100001] = {0, };

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;
    cache[4] = 1;
    cache[5] = 2;
    cache[6] = 3;
    cache[7] = 4;
    cache[8] = 2;
    cache[9] = 1;
    cache[10] = 2;

    int n;
    cin >> n;

    int sqrtn = static_cast<int>(sqrt(n));

    for(int i=11; i<=n; ++i)
    {
        cache[i] = 99999;
        int j = 0;
        do
        {
            j++;
            cache[i] = min(1 + cache[i - j * j], cache[i]);
        } while ((j+1) * (j+1) <= i);
    }

    cout << cache[n] << endl;

    return 0;
}
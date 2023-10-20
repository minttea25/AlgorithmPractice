// 카잉 달력
// https://www.acmicpc.net/problem/6064

#include <iostream>
#include <numeric>

using namespace std;

int solve(const int m, const int n, const int x, const int y)
{
    int k = -1;

    const int max_it = m * n / std::gcd(m, n);
    for(int i=x; i<=max_it; i+=m)
    {
        const int yy = (i-1)%n + 1;
        if (yy == y)
        {
            k = i;
            break;
        }
    }

    return k;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int tc;
    cin >> tc;

    while(tc > 0)
    {
        tc--;

        int m, n, x, y;
        cin >> m >> n >> x >> y;

        cout << solve(m, n, x, y) << '\n';
    }

    return 0;
}
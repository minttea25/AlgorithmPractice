// 내려가기
// https://www.acmicpc.net/problem/2096

#include <iostream>
#include <vector>

#define mn(info) info.first
#define mx(info) info.second

using namespace std;

using info = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    info cache[3] = { {0, 0}, {0, 0}, {0, 0} };

    for(int i=0; i<n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        const int mn1 = min(mn(cache[0]), mn(cache[1])) + a;
        const int mn2 = min(mn(cache[0]), min(mn(cache[1]), mn(cache[2]))) + b;
        const int mn3 = min(mn(cache[1]), mn(cache[2])) + c;

        const int mx1 = max(mx(cache[0]), mx(cache[1])) + a;
        const int mx2 = max(mx(cache[0]), max(mx(cache[1]), mx(cache[2]))) + b;
        const int mx3 = max(mx(cache[1]), mx(cache[2])) + c;

        mn(cache[0]) = mn1;
        mn(cache[1]) = mn2;
        mn(cache[2]) = mn3;
        mx(cache[0]) = mx1;
        mx(cache[1]) = mx2;
        mx(cache[2]) = mx3;
    }

    int ans_max = max(mx(cache[0]), max(mx(cache[1]), mx(cache[2])));
    int ans_min = min(mn(cache[0]), min(mn(cache[1]), mn(cache[2])));

    cout << ans_max << ' ' << ans_min << '\n';

    return 0;
}
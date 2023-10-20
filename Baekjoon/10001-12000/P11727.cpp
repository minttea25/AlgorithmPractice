// 2 * n 타일링 2
// https://www.acmicpc.net/problem/11727

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<unsigned long long> cache {1, 1, 3};
    for(int i=3; i<=n; ++i)
    {
        cache.push_back((cache[i-2] * 2 + cache[i-1]) % 10007);
    }

    cout << cache[n] << '\n';

    return 0;
}
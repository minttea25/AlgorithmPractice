// 파도반 수열
// https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    vector<long long> cache{0, 1, 1, 1, 2, 2, 3};
    for(int i=7; i<101; ++i)
    {
        cache.push_back(cache[i-1] + cache[i-5]);
    }

    int t;
    cin >> t;

    while (t > 0)
    {
        --t;

        int n;
        cin >> n;
        cout << cache[n] << '\n';
    }

    return 0;
}
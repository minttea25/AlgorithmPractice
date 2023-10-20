// 동전
// https://www.acmicpc.net/problem/9084

#include <iostream>
#include <vector>

using namespace std;

int count(const int m, const int n_coin, const vector<int>& coins, vector<vector<int>>& cache)
{
    if (m == 0) return 1;
    else if (m < 0) return 0;

    int& ret = cache[m][n_coin];
    if (ret != -1) return ret;

    ret = 0;
    for(int i=n_coin; i>=0; --i)
    {
        ret += count(m - coins[i], i, coins, cache);
    }

    return ret;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    vector<vector<int>> cache(10001);
    for(int i=0; i<10001; ++i) 
    {
        cache[i] = vector<int>(21);
        for (int j=0; j<21; ++j) cache[i][j] = -1;
    }

    int tc;
    cin >> tc;

    for(int i=0; i<tc; ++i) 
    {
        for(int i=0; i<10001; ++i) 
        {
            for (int j=0; j<21; ++j) cache[i][j] = -1;
        }

        int n;
        int m;
        vector<int> coins;
        cin >> n;
        for(int j=0; j<n; ++j) 
        {
            int t;
            cin >> t;

            coins.push_back(t);
        }
        cin >> m;

        cout << count(m, n-1, coins, cache) << '\n';
    }

    return 0;
}
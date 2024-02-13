// 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int get_sum(pair<int, int> p1, pair<int, int> p2, const vector<vector<int>>& table) 
{
    int total = table[p2.first][p2.second];

    if (p1.first == 0 && p1.second == 0) return total;

    int sector_a = p1.first-1 < 0 || p1.second-1 < 0 ? 0 : table[p1.first-1][p1.second-1];
    int sector_b = p1.first-1 < 0 ? 0 : table[p1.first - 1][p2.second];
    int sector_c = p1.second-1 < 0 ? 0 : table[p2.first][p1.second - 1];

    return total + sector_a - sector_b - sector_c;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>());
    for (int i=0; i<n; ++i) 
    {
        for (int j=0; j<n; ++j)
        {
            int t;
            cin >> t;
            table[i].push_back(t);
        }
    }

    for (int i=0; i<n; ++i)
    {
        for (int j=1; j<n; ++j)
        {
            table[i][j] += table[i][j-1];
        }
    }

    for (int i=1; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            table[i][j] += table[i-1][j];
        }
    }

    while (m > 0)
    {
        m--;

        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << get_sum({x1-1, y1-1}, {x2-1, y2-1}, table) << endl;
    }

    return 0;
}
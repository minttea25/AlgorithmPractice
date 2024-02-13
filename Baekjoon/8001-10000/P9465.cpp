// 스티커
// https://www.acmicpc.net/problem/9465

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int solve(const vector<vector<int>>& table)
{
    const int n = table.size();
    vector<vector<int>> v(n, vector<int>(3));
    
    v[0][0] = table[0][0]; // case a
    v[0][1] = table[0][1]; // case b
    v[0][2] = 0; // case c


    for (int i=1; i<n; ++i)
    {
        v[i][0] = table[i][0] +  max(v[i-1][1], v[i-1][2]); // A = A + max(b, c)
        v[i][1] = table[i][1] + max(v[i-1][0], v[i-1][2]); // B = B + max(a, c)
        v[i][2] = 0 + max(v[i-1][0], max(v[i-1][1], v[i-1][2])); // C = C + max(a, b)
    }

    return max(v[n-1][0], max(v[n-1][1], v[n-1][2]));
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int tc;
    cin >> tc;

    while (tc > 0) 
    {
        tc--;

        int n;
        cin >> n;
        
        vector<vector<int>> table(n, vector<int>(2));
        for (int i=0; i<2; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                int input;
                cin >> input;

                table[j][i] = input;
            }
        }

        cout << solve(table) << endl;
    }


    return 0;
}
// LCS
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <cstring>

using namespace std;

short cache[1001][1001];

short LCS(const int i, const int j, const string& s, const string& t)
{
    if (i < 0 || j < 0) return 0;

    short& ret = cache[i][j];

    if (ret != -1) return ret;

    if (s[i] == t[j]) ret = LCS(i-1, j-1, s, t) + 1;
    else ret = max(LCS(i-1, j, s, t), LCS(i, j-1, s, t));

    return ret;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    fill_n(&cache[0][0], 1001 * 1001, -1);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    const int i = s.size() - 1;
    const int j = t.size() - 1;

    cout << LCS(i, j, s, t) << endl;

    return 0;
}
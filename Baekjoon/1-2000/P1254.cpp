// 팰린드롬 만들기
// https://www.acmicpc.net/problem/1254

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    const int n = s.size();
    int ans = 2 * n - 1;
    int middle = 99999;

    for (int i=1; i<n; ++i)
    {
        if (s[i-1] == s[i])
        {
            int a = i - 1;
            int b = i;

            while (b < n && s[b] == s[a])
            {
                a--;
                b++;
                if (b == n)
                {
                    middle = i;
                    ans = middle * 2;
                }
            }
        }

        if (middle != 99999) break;
    }

    for (int i=2; i<n; ++i)
    {
        if (middle < i) break;

        if (s[i-2] == s[i])
        {
            int a = i - 2;
            int b = i;

            while (b < n && s[b] == s[a])
            {
                a--;
                b++;
                if (b == n)
                {
                    middle = i - 1;
                    ans = middle * 2 + 1;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
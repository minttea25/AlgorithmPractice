// IOIOI
// https://www.acmicpc.net/problem/5525

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int ans = 0;
    int seq = 0;
    bool flag = false;
    for(int i=0; i<m-1; ++i)
    {
        if (flag == false && s[i] == 'I') flag = true;
        else if (flag == true && s[i] == 'O' && s[i+1] == 'I')
        {
            ++i;
            seq++;
            if (seq >= n) ans++;
        }
        else if (s[i] == 'I') seq = 0;
        else
        {
            flag = false;
            seq = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
// 찾기
// https://www.acmicpc.net/problem/1786

#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(const string& s)
{
    const int size = s.size();
    vector<int> pi(size, 0);

    int begin = 1;
    int matched = 0;
    while (begin + matched < size)
    {
        if (s[begin + matched] == s[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
            {
                begin++;
            }
            else
            {
                // cut
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}


vector<int> kmp(const string& s, const string& n)
{
    const int s_len = s.size();
    const int n_len = n.size();
    vector<int> pi = getPi(n);

    vector<int> ret;

    int begin = 0; // start at 0 to check all chars in s
    int matched = 0;
    while(begin + n_len <= s_len)
    {
        if (matched < n_len && n[matched] == s[begin + matched])
        {
            matched++;
            if (matched == n_len) ret.push_back(begin);
        }
        else
        {
            if (matched == 0)
            {
                begin++;
            }
            else 
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

int main() 
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    auto ret = kmp(t, p);

    cout << ret.size() << '\n';
    for(int i=0; i<ret.size(); ++i)
    {
        cout << ret[i] + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
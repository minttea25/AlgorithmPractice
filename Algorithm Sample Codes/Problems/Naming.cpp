#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(const string& s)
{
    const int size = s.size();
    vector<int> pi(size, 0);

    int begin = 1;
    int matched = 0;
    while(begin + matched < size)
    {
        if (s[matched] == s[begin + matched])
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

int main() 
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string s = "ababbaba";


    auto ss = getPi(s);
    int k = ss.size();
    while(k > 0) {
        cout << k << ' ';
        k = ss[k-1];
    }

    return 0;
}
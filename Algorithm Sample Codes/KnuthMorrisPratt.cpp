#include <iostream>
#include <vector>

using namespace std;

vector<int> getPi(const string& s)
{
    const int n = s.size();
    vector<int> pi(n, 0);

    // begin=1 부터 시작하여 자신과 일치하는 문자열 찾기 (자신을 제외하기 위해 1부터 시작)
    int matched = 0;
    int begin = 1;
    while(begin + matched < n)
    {
        if (s[matched] == s[begin + matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else 
        {
            // 0, 1이 다를경우 => 다음 prefix 확인
            if (matched == 0) begin++;
            else
            {
                // 일치하기 시작했던 부분(begin)부터 matched 값만큼 다시 확인 시작
                begin += matched - pi[matched - 1];
                // 일치하는데까지 건너뛰기
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

// 문자열 s에서 n과 일치하는 문자열의 시작 index를 담고 있는 vector 반환
vector<int> kmp(const string& s, const string& n)
{
    const int len = s.size();
    const int n_len = n.size();
    const vector<int> pi = getPi(n);

    vector<int> ret;

    // begin = 0 부터(처음부터) 문자 일치 확인
    int begin = 0;
    int matched = 0;
    while (begin + n_len <= len)
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
                // 건너뛰기
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

    string s = "baabaabacabaabacc";
    string n = "aaba";

    auto v = kmp(s, n);

    cout << "s: " << s << endl;
    cout << "n: " << n << endl;

    for(int i=0; i<v.size(); ++i)
    {
        cout << "[" << v[i] << ", " << v[i] + n.size()-1 << "]: " << n << endl;

    }

    return 0;
}
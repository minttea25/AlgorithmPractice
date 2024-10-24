#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 부분 일치 테이블 생성
vector<int> getPartialMatch(const string& str)
{
    const int size = str.size();
    vector<int> pi(size, 0);

    // kmp로 자기 자신을 찾는다.
    // str에서 str를 찾기
    // begin = 0은 자기 자신이므로 제외
    int begin = 1, matched = 0;
    // 비교할 문자가 str의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록
    while (begin + matched < size)
    {
        // 확인할 문자가 일치하는지
        if (str[begin + matched] == str[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0) begin++; // 다음 문자 확인
            else // 이전에 일치 문자가 있었으나 현재는 더 이상 일치하지 않는 경우
            {
                // 일치했던 만큼 건너뛰기
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

vector<int> kmp(const string& str, const string& pattern)
{
    vector<int> ret;

    const int size = str.size();
    const int pattern_size = pattern.size();

    int begin = 0;
    int matched = 0;
    auto pi = getPartialMatch(pattern);

    while (begin + pattern_size <= size)
    {
        if (matched < pattern_size && str[begin + matched] == pattern[matched])
        {
            matched++;
            // 완전히 일치 했을 때
            if (matched == pattern_size) 
            {
                ret.push_back(begin);
            }
        }
        else
        {
            // 현재 문자가 일치하지도 않고 이전에도 일치한 문자가 없었을 때
            // 다음 문자 확인
            if (matched == 0) begin++;
            // 이전에 문자가 일치 했었을 때
            else
            {
                // 테이블 값만 큼 건너뛰어 확인
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return ret;
}






int main()
{
    string s0 = "abaabcaabca";
    string s1 = "aabca"; // 0 1 0 0 1
    string s2 = "aaababc"; // 1 2 0 1 0 0
    auto pi = getPartialMatch(s1); 
    for(const auto& i : pi)
    {
        cout << i << ' ';
    }
    cout << endl;

    auto index = kmp(s0, s1);
    for(const auto& i : index)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;

}
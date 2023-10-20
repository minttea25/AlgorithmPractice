// 둘만의 암호
// https://school.programmers.co.kr/learn/courses/30/lessons/176963

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAX = 26;
char keys[MAX];
int s_keys;

// if string is short => copy the value 
// so for 'sort' and 'unique', make refer.
void makeKeys(string& skip)
{
    sort(skip.begin(), skip.end());
    skip.erase(unique(skip.begin(), skip.end()), skip.end());

    s_keys = MAX - skip.size();

    int idx = 0;
    int s_idx = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (s_idx < skip.size() && (char)i == skip[s_idx])
        {
            s_idx++;
            continue;
        }

        keys[idx++] = (char)i;
    }
}

char getKey(char start, string skip, int index)
{
    int i = start - 'a' - (lower_bound(skip.begin(), skip.end(), start) - skip.begin()) + index;

    return keys[i % s_keys];
}

string solution(string s, string skip, int index) {
    makeKeys(skip);
    vector<char> ans;
    for (int i = 0; i < s.size(); i++)
    {
        ans.push_back(getKey(s[i], skip, index));
        cout << ans[i] << endl;
    }
    string answer(ans.begin(), ans.end());
    return answer;
}
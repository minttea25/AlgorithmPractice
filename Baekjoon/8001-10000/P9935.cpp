// 문자열 폭발
// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::string t;
    std::cin >> s;
    std::cin >> t;

    std::stack<char> st;
    std::stack<char> result;
    for (const char c : s)
    {
        st.push(c);
    }

    int idx = t.size() - 1;
    while (st.empty() == false)
    {
        char c = st.top();
        st.pop();

        result.push(c);

        if (c == t.at(idx)) idx--;
        else
        {
            idx = t.size() - 1;
            if (c == t.at(idx)) idx--;
        }

        // found t string
        if (idx == -1)
        {
            for (int i=0; i<t.size(); ++i)
            {
                result.pop();
            }

            for (int i=0; i<t.size(); ++i)
            {
                if (result.empty() == false) 
                {
                    st.push(result.top());
                    result.pop();
                }
                else break;
            }

            idx = t.size() - 1;
        }
    }

    if (result.empty()) std::cout << "FRULA" << std::endl;
    else
    {
        while(result.empty() == false)
        {
            char c = result.top();
            result.pop();
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}
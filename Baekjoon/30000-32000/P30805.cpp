// 사전 순 최대 공통 부분 수열
// https://www.acmicpc.net/problem/30805

#include <iostream>
#include <vector>
#include <algorithm>

using pii = std::pair<int, int>;

struct PiiComp
{
    bool operator()(const pii& lhs, const pii& rhs)
    {
        if (lhs.first != rhs.first) return lhs.first > rhs.first;
        else return lhs.second < rhs.second;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a_size;
    int b_size;
    std::vector<pii> a;
    std::vector<pii> b;

    int mx;
    
    std::cin >> a_size;
    for (int i=0; i<a_size; ++i)
    {
        int input;
        std::cin >> input;
        a.push_back({input, i});
    }

    std::cin >> b_size;
    for (int i=0; i<b_size; ++i)
    {
        int input;
        std::cin >> input;
        b.push_back({input, i});
    }

    std::stable_sort(a.begin(), a.end(), PiiComp());
    std::stable_sort(b.begin(), b.end(), PiiComp());

    int pa = 0;
    int pb = 0;
    int ai = -1;
    int bi = -1;
    std::vector<int> ans;

    while (pa < a_size && pb < b_size)
    {
        if (a[pa].first == b[pb].first 
            && a[pa].second > ai 
            && b[pb].second > bi)
        {
            ai = a[pa].second;
            bi = b[pb].second;
            ans.push_back(a[pa].first);

            pa++;
            pb++;
        }
        else
        {
            if (a[pa].first > b[pb].first || a[pa].second < ai) pa++;
            if (a[pa].first < b[pb].first || b[pb].second < bi) pb++;
        }
    }

    std::cout << ans.size() << '\n';
    if (ans.size() != 0)
    {
        for (const auto& e : ans)
        {
            std::cout << e << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
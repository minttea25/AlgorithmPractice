// 회의실 배정
// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <queue>

using pii = std::pair<int ,int>;

struct com
{
    bool operator()(const pii& lhs, const pii& rhs)
    {
        if (lhs.second != rhs.second)
            return lhs.second > rhs.second;
        else
            return lhs.first > rhs.first;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::priority_queue<pii, std::vector<pii>, com> pq;

    int n;
    std::cin >> n;

    for (int i=0; i<n; ++i)
    {
        int s, e;
        std::cin >> s >> e;
        pq.push({s, e});
    }

    // TEST
    // while (pq.empty() == false)
    // {
    //     auto a = pq.top();
    //     pq.pop();

    //     std::cout << a.first <<  ' ' << a.second << std::endl;
    // }

    int count = 0;
    int begin = 0;
    int end = 0;
    while (pq.empty() == false)
    {
        auto t = pq.top();
        pq.pop();
        
        if (t.first >= end)
        {
            begin = t.first;
            end = t.second;

            count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}
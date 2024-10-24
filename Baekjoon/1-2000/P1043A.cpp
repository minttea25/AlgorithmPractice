// 거짓말
// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <queue>

using Party = std::vector<std::vector<int>>;
using People = std::vector<std::vector<int>>;

void SpreadTrueTale(
    const Party& parties, 
    const People& people, 
    std::vector<bool>& visited,
    std::vector<bool>& uso_dekiru_parties,
    const int person_who_know_truth)
{
    // use bfs with queue
    std::queue<int> q;
    q.push(person_who_know_truth);
    visited[person_who_know_truth] = true;
    
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();

        
        for(const auto& party : people[p])
        {
            if (uso_dekiru_parties[party] == false) continue;
            uso_dekiru_parties[party] = false;
            for (const auto& person : parties[party])
            {
                if (visited[person] == false)
                {
                    visited[person] = true;
                    q.push(person);
                }
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int truth;
    std::cin >> truth;

    std::vector<int> people_who_know_truth;
    Party parties(m, std::vector<int>()); // party - participants
    People people(n, std::vector<int>()); // people - parties

    for (int i=0; i<truth; ++i)
    {
        int t;
        std::cin >> t;
        people_who_know_truth.push_back(t-1);
    }

    for (int i=0; i<m; ++i)
    {
        int cnt;
        std::cin >> cnt;
        for (int ii=0; ii<cnt; ++ii)
        {
            int t;
            std::cin >> t;
            parties[i].push_back(t-1);
            people[t-1].push_back(i);
        }
    }

    // connected - components

    std::vector<bool> uso_dekiru_party(m, true);
    std::vector<bool> visited(n, false);
    for (const auto& p : people_who_know_truth)
    {
        if (visited[p] == false)
            SpreadTrueTale(parties, people, visited, uso_dekiru_party, p);
    }
    
    int ans = 0;
    for(const auto& p : uso_dekiru_party)
    {
        if (p == true) ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}

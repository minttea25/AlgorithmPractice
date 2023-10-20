// 거짓말
// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; // 사람의 수
    int m; // 파티의 수
    cin >> n >> m;

    vector<bool> trues(n, false);
    int s;
    cin >> s;
    for (int i = 0; i < s; ++i)
    {
        int input;
        cin >> input;
        trues[input - 1] = true;
    }

    // 사람 - 참가 파티
    // 만날 수 있나 ?
    vector<vector<int>> people(n, vector<int>());
    vector<vector<int>> parties(m, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int size;
        cin >> size;
        for (int ii = 0; ii < size; ++ii)
        {
            int p;
            cin >> p;
            people[p - 1].push_back(i);
            parties[i].push_back(p - 1);
        }
    }

    vector<bool> visited(m, false);
    for (int i = 0; i < n; ++i)
    {
        if (trues[i] == false) continue;

        queue<int> q; //party

        for (const auto& p : people[i])
        {
            if (visited[p] == false)
            {
                q.push(p);
                visited[p] = true;
            }
        }

        while (q.empty() == false)
        {
            auto cur = q.front();
            q.pop();

            for (int ii = 0; ii < parties[cur].size(); ++ii)
            {
                const int person = parties[cur][ii];
                if (trues[person] == false)
                {
                    trues[person] = true;

                    for (const auto& party : people[person])
                    {
                        if (visited[party] == false)
                        {
                            q.push(party);
                            visited[party] = true;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (const auto& v : visited)
    {
        if (v == false) ans++;
    }

    cout << ans << '\n';

    return 0;
}
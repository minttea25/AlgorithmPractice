// 숨바꼭질
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <vector>

constexpr const int MAX = 199'999;
constexpr const int DUMMY = -1;

constexpr bool CheckBound(const int i)
{
    return i >=0 && i <= MAX;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    // bfs
    std::vector<bool> visited(MAX + 1, false);
    std::queue<int> q;

    q.push(n);
    visited[n] = true;
    q.push(DUMMY);

    int count = 0;
    while (q.empty() == false) 
    {
        auto p = q.front();
        q.pop();

        if (p == DUMMY)
        {
            if (q.empty())
            {
                break; // unreachable
            }
            else
            {
                q.push(DUMMY);
                count++;
                continue;
            }
        }

        if (p == k) break;

        int left = CheckBound(p - 1) ? p - 1 : -1;
        if (left != -1 && visited[left] == false)
        {
            visited[left] = true;
            q.push(left);
        }
        int right = CheckBound(p + 1) ? p + 1 : -1;
        if (right != -1 && visited[right] == false)
        {
            visited[right] = true;
            q.push(right);
        }
        int teleport = CheckBound(p * 2) ? p * 2 : -1;
        if (teleport != -1 && visited[teleport] == false)
        {
            visited[teleport] = true;
            q.push(teleport);
        }
    }

    std::cout << count << std::endl;

    return 0;
}
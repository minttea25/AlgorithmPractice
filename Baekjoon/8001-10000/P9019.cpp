// DSLR
// https://www.acmicpc.net/problem/9019

#include <iostream>
#include <queue>

using namespace std;

using ushort = unsigned short;

using element = pair<ushort, string>;

constexpr ushort op_D(const ushort& n)
{
    return (n*2) % 10000;
}

constexpr ushort op_S(const ushort& n)
{
    return n == 0 ? 9999 : n-1;
}

constexpr ushort op_L(const ushort& n)
{
    if (n < 1000) return n*10;
    else return ((n%1000)*10) + (n/1000);
}

constexpr ushort op_R(const ushort& n)
{
    if (n < 10) return n*1000;
    else return n/10 + ((n%10) * 1000);
}

string bfs(const ushort start, const ushort goal)
{
    bool visited[10000] = {false, };
    visited[start] = true;
    queue<element> q;
    q.push({start, ""});

    while(q.empty() == false)
    {
        element current = q.front();
        q.pop();

        const ushort d = op_D(current.first);
        const string dd = current.second + 'D';
        if (d == goal) return dd;
        if (visited[d] == false)
        {
            visited[d] = true;
            q.push({d, dd});
        }
        
        const ushort s = op_S(current.first);
        const string ss = current.second + 'S';
        if (s == goal) return ss;
        if (visited[s] == false)
        {
            visited[s] = true;
            q.push({s, ss});
        }

        const ushort l = op_L(current.first);
        const string ll = current.second + 'L';
        if (l == goal) return ll;
        if (visited[l] == false)
        {
            visited[l] = true;
            q.push({l, ll});
        }

        const ushort r = op_R(current.first);
        const string rr = current.second + 'R';
        if (r == goal) return rr;
        if (visited[r] == false)
        {
            visited[r] = true;
            q.push({r, rr});
        }
    }

    return "";
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    ushort t;
    cin >> t;

    while (t > 0)
    {
        --t;

        ushort a, b;
        cin >> a >> b;

        cout << bfs(a, b) << '\n';
    }

    return 0;
}
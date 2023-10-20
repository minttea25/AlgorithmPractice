// 소문난 칠공주
// https://www.acmicpc.net/problem/1941

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int CONDITION = 403;

constexpr pair<int, int> dir[4] = 
{
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}
};

int farm[5][5];

bool checkConnected(const vector<bool>& check)
{
    pair<int, int> pos;

    for(int i=0; i<check.size(); ++i) 
    {
        if (check[i] == true)
        {
            pos = {i/5, i%5};
            break;
        }
    }

    int cnt = 0;
    vector<bool> visited(25, false);
    queue<pair<int, int>> q;

    visited[pos.first*5 + pos.second] = true;
    q.push(pos);
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();

        cnt++;

        for(int i=0; i<4; ++i)
        {
            int x = p.first + dir[i].first;
            int y = p.second + dir[i].second;

            if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;

            if (check[x*5 + y] == true && visited[x*5 + y] == false)
            {
                visited[x*5 + y] = true;
                q.push({x, y});
            }
        }
        //cout << p.first*5+p.second << ' ';
    }
    //cout << endl;
    return cnt == 7;
}

void makeGroup(const int n, const int chosen, vector<bool>& check, int& ans)
{
    if (chosen == 7) 
    {
        //for(int i=0; i<check.size(); ++i) cout << check[i] << ' ';
        //cout << endl;

        int state = 0;
        for(int i=0; i<check.size(); ++i)
        {
            if (check[i] == true) state += farm[i/5][i%5];
        }
        if (state >= CONDITION && checkConnected(check) == true) ans++; 
        return;
    }

    if (25 - n < 7 - chosen) return;

    check[n] = true;
    makeGroup(n+1, chosen + 1, check, ans);

    check[n] = false;
    makeGroup(n+1, chosen, check, ans);
}

int main() 
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string s;
    int ns = 0;
    for(int i=0; i<5; ++i)
    {
        cin >> s;
        for(int ii=0; ii<s.size(); ++ii)
        {
            farm[i][ii] = s[ii] == 'S' ? 100 : 1;
            ns += s[ii] == 'S';
        }
    }

    if (ns < 4)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    vector<bool> check(25, false);
    makeGroup(0, 0, check, ans);

    cout << ans << endl;


    for(int i=0; i<5; ++i)
    {
        for(int ii=0; ii<5; ++ii)
        {
            cout << farm[i][ii] << ' ';
        }
        cout << endl;
    }

    return 0;
}
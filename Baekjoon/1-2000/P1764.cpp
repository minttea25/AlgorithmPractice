// 듣보잡
// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    cin.ignore(100000, '\n');

    vector<string> idw;
    for(int i=0; i<n; ++i)
    {
        string name;
        getline(cin, name);
        idw.push_back(name);
    }

    sort(idw.begin(), idw.end());

    vector<string> ans;
    for(int i=0; i<m; ++i)
    {
        string name;
        getline(cin, name);

        auto it = lower_bound(idw.begin(), idw.end(), name);
        if (name.compare(*it) == 0) ans.push_back(name);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(const string& name : ans) cout << name << '\n';

    return 0;
}
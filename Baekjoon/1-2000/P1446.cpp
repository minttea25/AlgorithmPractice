// 지름길
// https://www.acmicpc.net/problem/1446

#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

using namespace std;

typedef pair<int, int> section;
typedef pair<section, int> highway;

int N, D; // N<=12 D<= 10000
vector<highway> highways;

int dp[13];

bool comp(const highway& a, const highway& b) {
    if (a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    else {
        return a.second < b.second;
    }
}

int findRoute(highway start, int ith) {
    if (dp[ith] != -1)
        return dp[ith];

    int len = start.second;

    // destination == end of highway(start)
    if (D == start.first.second) {
        dp[ith] = len;
        return len;
    }

    int t = 1e9;
    bool flag = false;
    // not arrived
    for (int i=ith+1; i<highways.size(); i++) {
        if (start.first.second > highways[i].first.first) {
            continue;
        }
        flag = true;
        t = min(highways[i].first.first - start.first.second + findRoute(highways[i], i), t);
    }

    // if start highway is the only highway to go
    if(!flag) {
        dp[ith] = len + D - start.first.second;
        return len + D - start.first.second;
    }

    dp[ith] = len+t;
    return len+t;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    fill_n(dp, 13, -1);

    int t1, t2, t3;
    int validCnt;
    int ans;

    cin >> N >> D;
    validCnt = N;
    ans = D;

    for (int i=0; i<N; i++) {
        cin >> t1 >> t2 >> t3;
        if (t2 - t1 <= t3 || t2 > D) {
            validCnt--;
            continue;
        }
        highways.push_back(highway(section(t1, t2), t3));
    }

    sort(begin(highways), end(highways), comp);

    // for checking sorted vector
    // for (int i=0; i<validCnt; i++) {
    //     cout << highways[i].first.first << " " << highways[i].first.second << " " << highways[i].second << endl;
    // }

    for (int i=0; i<validCnt; i++) {
        int a = highways[i].first.first + findRoute(highways[i], i);
        ans = min(a, ans);
    }

    cout << ans << endl;

    return 0;
}
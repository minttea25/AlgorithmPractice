// p.454: 캐나다 여행

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

constexpr int MAX = numeric_limits<int>().max();

bool checkNumOfSigns(vector<int>& l, vector<int>& m, vector<int>& g, int dist, int n) {
    int cnt = 0;
    for (int i=0; i<l.size(); ++i) {
        if (dist > l[i] - m[i]) cnt += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
    }
    return cnt >= n;
}

int solve(vector<int>& l, vector<int>& m, vector<int>& g, int n) {
    // binary serach
    int left = 0;
    int right = MAX;

    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (checkNumOfSigns(l, m, g, mid, n) == true) right = mid;
        else left = mid;
    }

    return right;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<int> l;
    vector<int> m;
    vector<int> g;

    int tc;
    cin >> tc;

    for (int i=0; i<tc; ++i) {
        l.clear();
        m.clear();
        g.clear();

        int n, k;
        cin >> n >> k;

        for (int j=0; j<n; ++j) {
            int l_in, m_in, g_in;
            cin >> l_in >> m_in >> g_in;
            l.push_back(l_in);
            m.push_back(m_in);
            g.push_back(g_in);
        }

        cout << solve(l, m, g, k) << endl;
    }

    return 0;
}

/* 
input
2
3 15
500 100 10
504 16 4
510 60 6
2 1234567
8030000 8030000 1
2 2 1
*/

/*
output
480
1234563
*/


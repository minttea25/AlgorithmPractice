// 고층 건물
// https://www.acmicpc.net/problem/1027

#include <iostream>
#include <vector>
#include <algorithm>

// It includes almost all header files for algorithm practice.
// It is not a standard library header for C++, but a valid header only with the gcc compiler.
// #include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

typedef pair<int, ll> ilp;

constexpr int MAX = 50;

int N;
int buildings[MAX+1];

// ccw algorithm
// For consecutive points a, b, c in a 2d plane,
// return positive if clockwise,
// return negative if counterclockwise
// return 0 if on a straight line.
ll ccw(ilp a, ilp b, ilp c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    FOR_(i, 1, N) {
        cin >> buildings[i];
    }   

    int mx = -1;
    int cnt = 0;
    FOR_(i, 1, N) {
        cnt = 0;
        FOR_(j, 1, N) {
            bool flag = true;
            if (j < i) {
                FOR(k, j+1, i) {
                    if (ccw({i, buildings[i]}, {k, buildings[k]}, {j, buildings[j]}) >= 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
            else if (i < j) {
                FOR(k, i+1, j) {
                    if (ccw({i, buildings[i]}, {k, buildings[k]}, {j, buildings[j]}) <= 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
            else {
                continue;
            }
        }

        mx = max(mx, cnt);
    }

    cout << mx << endl;

    return 0;
}
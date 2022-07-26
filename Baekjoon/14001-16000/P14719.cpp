// 빗물의 양
// https://www.acmicpc.net/problem/14719

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

constexpr int MAX = 501;

int H, W;
int in[MAX];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> H >> W;

    FOR(i, 0, W) {
        cin >> in[i];
    }
    int amount = 0;
    int check = -1;

    FOR (r, 0, H) {
        FOR (c, 0, W) {
            if (check != -1 && in[c] - r > 0) {
                amount += (c - check - 1);
                check = c;
            }
            else if (in[c] - r > 0) {
                check = c;
            }
        }
        check = -1;
    }

    cout << amount << endl;

    return 0;
}
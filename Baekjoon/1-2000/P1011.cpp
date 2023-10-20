// Fly me to the Alpha Centauri
// https://www.acmicpc.net/problem/1011

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

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int T;

    cin >> T;

    FOR(i, 0, T) {
        ll x, y;
        cin >> x >> y;
        ll dist = y - x;
        ll t = 1;
        ll cnt = 0;

        while (true) {
            cnt++;
            if (dist <= t*t) {
                cout << cnt << endl;
                break;
            }

            cnt++;
            if (dist <= t*(t+1)) {
                cout << cnt << endl;
                break;
            }
            t++;
        }
    }

    return 0;
}
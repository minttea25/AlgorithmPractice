//  Moo 게임
// https://www.acmicpc.net/problem/5904

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

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;
typedef pair<ll, ll> llp;

ll N;

llp getIter(const ll& n) {
    if (n<=3) return {0, 0};

    ll t = 3;
    for(ll i=1; ; i++) {
        t = (t*2) + i + 3ll;

        if (t > n) {
            return {i, (t-i-3ll) / 2};
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    ll now = N - 1;
    while(true) {
        llp it = getIter(now);
        now = now - it.second;
        if (now == 0) {
            cout << 'm' << endl;
            break;
        }
        else if (now < it.first + 2 + 1) {
            cout << 'o' << endl;
            break;
        }
        now = now - it.first - 2 - 1;

    }
    return 0;
}
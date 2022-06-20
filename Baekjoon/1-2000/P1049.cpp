// 기타줄
// https://www.acmicpc.net/problem/1049

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

constexpr int NPKG = 6;

int n, m;
int pkgMn;
int eachMn;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b;
    pkgMn = 100000000;
    eachMn = 100000000;

    cin >> n >> m;

    FOR(i, 0, m) {
        cin >> a >> b;

        // the price of a package is more expensive than each*6
        if (a > b*NPKG) {
            a = b * NPKG;
        }
        
        pkgMn = min (a, pkgMn);
        eachMn = min (b, eachMn);
    }

    int pp = n / NPKG; 
    int ee = n % NPKG;

    int t1 = pp*pkgMn + ee*eachMn;
    int t2 = (pp+1)*pkgMn;

    cout << min(t1, t2) << endl;

    return 0;
}
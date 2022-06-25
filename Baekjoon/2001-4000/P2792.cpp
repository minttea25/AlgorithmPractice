// 보석상자
// https://www.acmicpc.net/problem/2792

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

int N, M;
int J[300001];

int calc(int mx) {
    int m;
    int t;
    int mxj = mx;
    int v = 1;
    while(mxj >= v) {
        m = (mxj+v)>>1;

        t = 0;
        FOR(i, 0, M) {
            t += J[i]/m;
            if (J[i] % m != 0) t++;
        }

        if (t <= N) {
            mxj = m - 1; // check if there is less ans
        }
        else {
            v = m + 1;
        }
    }

    return v;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    ll sum = 0;
    int mx = -1;
    cin >> N >> M;

    FOR(i, 0, M) {
        cin >> J[i];
        sum += J[i];
        mx = max(mx, J[i]);
    }

    if (sum <= N) {
        cout << 1 << endl;
    }
    else {
        cout << calc(mx) << endl;
    }

    return 0;
}
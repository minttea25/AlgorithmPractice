// 쉽게 푸는 문제
// https://www.acmicpc.net/problem/1292

#include <iostream>
#include <vector>

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

// maximum of A, B is 1000
constexpr int MAX = 46; // sum of n -> (n(n+1))/2 should more than 1000
constexpr int IDXMAX = (MAX * (MAX+1))/2;
int SUM[IDXMAX];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b;

    cin >> a >> b;

    int idx = 1;

    SUM[0] = 0;
    FOR(i, 1, MAX) {
        FOR(j, 0, i) {
            SUM[idx] = SUM[idx-1] + i;
            idx++;
        }
    }

    cout << SUM[b] - SUM[a-1] << endl;

    return 0;
}
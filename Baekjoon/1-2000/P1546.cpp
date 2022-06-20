// 평균
// https://www.acmicpc.net/problem/1546

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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int T, sum = 0;
    int score;
    int mx = -1;
    cin >> T;

    for (int i=0; i<T; i++) {
        cin >> score;
        sum += score;

        mx = max (score, mx);
    }

    cout << (100*sum)/(double)(T*mx);

    return 0;
}
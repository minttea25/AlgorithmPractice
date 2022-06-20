// 1로 만들기
// https://www.acmicpc.net/problem/1463

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

int dp[1000001];

int getDP(int n) {
    if (n==0 || n==1) return 0;

    if (dp[n] == 0) {
        if (n%6==0) dp[n] = min(min(getDP(n/2), getDP(n/3)), getDP(n-1)) + 1;
        else if (n%3==0) dp[n] = min(getDP(n/3), getDP(n-1)) + 1;
        else if (n%2==0) dp[n] = min(getDP(n/2), getDP(n-1)) + 1;
        else dp[n] = getDP(n-1) + 1;
    }

    return dp[n];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    cout << getDP(n) << endl;

    return 0;
}
// 잃어버린 괄호
// https://www.acmicpc.net/problem/1541

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

    string s;
    cin >> s;

    int ans = 0;
    bool minusFlag = false;
    int a = 0, count = 0;

    FOR(i, 0, s.length()) {
        if (s[i] == '+' || s[i] == '-' || i+1 == s.length()) {
            if (s.length() == i+1) count++;

            if (minusFlag) {
                ans -= stoi(s.substr(a, count));
            }
            else {
                ans += stoi(s.substr(a, count));
            }

            if (s[i] == '-') minusFlag = true;

            count = -1;
            a = i+1;
        }
        count++;
    }

    cout << ans << endl;

    return 0;
}
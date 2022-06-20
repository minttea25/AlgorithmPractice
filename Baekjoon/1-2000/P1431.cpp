// 시리얼 번호
// https://www.acmicpc.net/problem/1431

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

string s[51];

bool comS(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }
    else if (s1.length() < s2.length()) {
        return true;
    }

    int sum1 = 0, sum2 = 0;
    FOR(i, 0, s1.length()) {
        if (s1[i] >= '0' && s1[i] <= '9') {
            sum1 += s1[i] - '0';
        }
        if (s2[i] >= '0' && s2[i] <= '9') {
            sum2 += s2[i] - '0';
        }
    }
    if (sum1 > sum2) {
        return false;
    }
    else if (sum1 < sum2) {
        return true;
    }

    FOR (i, 0, s1.length()) {
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        
        if (a > b) {
            return false;
        }
        else if (a < b) {
            return true;
        }
    }

    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;

    cin >> n;

    FOR(i, 0, n) {
        cin >> s[i];
    }

    sort(s, s+n, comS);

    FOR(i, 0, n) {
        cout << s[i] << endl;
    }

    return 0;
}
// 신입사원
// https://www.acmicpc.net/problem/1946

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
// #include <bits/stdc++.h>

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

bool CMP(iip e1, iip e2) {
    return e1.first < e2.first;
}

constexpr int MAX = 100001;

iip r[MAX];

int T;
int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b;
    int cnt;
    int mn;

    cin >> T;
    while(T>0) {
        cnt = 0;
        cin >> N;
        FOR(i, 0, N) {
            cin >> r[i].first;
            cin >> r[i].second;
        }

        sort(r, r+N, CMP);

        mn = r[0].second;
        FOR_(i, 1, N) {
            if (r[i].second < mn)  {
                mn = r[i].second;
                cnt++;
            }
        }

        cout << cnt << endl;

        T--;
    }

    return 0;
}
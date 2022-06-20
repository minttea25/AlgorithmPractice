// 숨바꼭질
// https://www.acmicpc.net/problem/1697

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

constexpr int MAX = 100000;

queue<int> q;
bool visited[100001] = {0, };

int N, K;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int cnt = 0;

    cin >> N >> K;

    if (N == K) {
        cout << 0 << endl;
        return 0;
    }

    q.push(N);

    while(!q.empty()) {
        int s = q.size();
        FOR(i, 0, s) {
            int p = q.front();
            q.pop();

            int pos[3] = {p+1, p-1, p*2};

            for (int e : pos) {
                if (e >= 0 && e <= MAX && !visited[e]) {
                    if (e == K) {
                        cout << cnt+1 << endl;
                        return 0;
                    }

                    visited[e] = true;
                    q.push(e);
                }
            }
        }
        cnt++;
    }

    return 0;
}
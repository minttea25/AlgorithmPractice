// 암호 만들기
// https://www.acmicpc.net/problem/1759

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

int L, C;
char h[16];
bool visited[16];

void dfs(int n, int depth) {
    if (depth == L) {
        int vowel = 0, con = 0;
        FOR(i, 0, C) {
            if (visited[i]) {
                if (h[i] == 'a' || h[i] == 'e' || h[i] == 'i' || h[i] == 'o' || h[i] == 'u') {
                    vowel++;
                }
                else {
                    con++;
                }
            }
        }

        if (vowel >= 1 && con >= 2) {
            FOR(i, 0, C) {
                if (visited[i]) cout << h[i];
            }
            cout << endl;
        }

        return;
    }

    FOR(i, n, C) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, depth+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> L >> C;

    FOR(i, 0, C) {
        cin >> h[i];
    }

    sort(h, h+C);

    dfs(0, 0);

    return 0;
}
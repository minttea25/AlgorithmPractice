// 숫자고르기
// https://www.acmicpc.net/problem/2668

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory.h>

// It includes almost all header files for algorithm practice.
// It is not a standard library header for C++, but a valid header only with the gcc compiler.
// #include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

int set[101];
bool valid[101];
bool VISITED[101] = {false, };
int N;

void DFS(int start, const int N)
{
    bool visited[N+1] = {false, };

    int idx=0;
    iv order;
    iv nth(N+1);

    visited[start] = true;
    order.push_back(start);
    nth[start] = idx;
    idx++;

    int now;
    int next = start;

    while(true) {
        now = set[next];
        if (visited[now] == true) {
            // get idx from map
            // check valid (from order[i] to order[order.size()-1])
            FOR(i, nth[now], order.size()) {
                valid[order[i]] = true;
            }
            break;
        }

        if (VISITED[now] == true) break;

        visited[now] = true;
        order.push_back(now);
        nth[now] = idx;
        idx++;

        next = now;
    }

    for(auto vi : order) {
        VISITED[vi] = true;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    FOR_(i, 1, N)
    {
        cin >> set[i];
    }

    FOR_(i, 1, N) {
        if (VISITED[i] == false) {
            DFS(i, N);

        }
    }

    int ans = 0;
    FOR_(i, 1, N) {
        if (valid[i] == true) ans++;
    }

    cout << ans << endl;
    FOR_(i, 1, N) {
        if (valid[i] == true) cout << i << endl;
    }

    return 0;
}
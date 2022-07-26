// 게리맨더링
// https://www.acmicpc.net/problem/17471

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

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

#define MAX 101
#define MAX2 11
#define DEFAULT 100000
#define endl '\n'

vector<int> nodes[MAX];
int pop[MAX2];
int sum = 0;
int mn = DEFAULT;
int fullSet;
int N;
bool visited[MAX2];
set<int> checkedSet;

// bit set 주어졌을 때 포함된 원소(노드)가 connected elements 인지 확인
int getP(int bit) {
    int point = 0;
    int start = -1;

    int subset[N+1];
    fill_n(subset, N+1, 0);
    
    // bit 에 포함된 노드는 1 값으로
    for (int i=1; i<N+1; i++) {
        if ((bit & (1<<i)) == 1<<i) {
            subset[i] = 1;
            if (start == -1) start = i;
        }
    }

    queue<int> q;
    fill_n(visited, MAX2, false);
    
    q.push(start);
    visited[start] = true;
    subset[start]++;

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        point += pop[p];
        for (int n : nodes[p]) {
            if (!visited[n] && subset[n] != 0) {
                visited[n] = true;
                subset[n]++; // 방문 했다면 2 이상의 값으로
                q.push(n);
            }
        }
    }

    for (int i=1; i<=N; i++) {
        if (subset[i] == 1) {
            return -1;
        }
    }

    return point;
}

void dfs(int start, int p, int bitSet, int n) {
    if (n == 0) {
        // 중복 확인 
        if (checkedSet.insert(bitSet).second) {
            int a = getP(bitSet);
            int b = getP(fullSet^bitSet);

            if (a != -1 && b != -1) {
                mn = min(abs(a-b), mn);
            }
            return;
        }
    }

    for (int i=start+1; i<=N; i++) {
        bitSet |= 1 << i; // add nodes i
        dfs(i, p + pop[i], bitSet, n-1);
        bitSet ^= 1 << i; // remove nodes i from set
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;

    cin >> N;
    for (int i=1; i<N+1; i++) {
        cin >> a;
        pop[i] = a;
        sum += pop[i];
    }

    fullSet = (1 << N+1) - 1 - 1; // 1 ~ 10

    for (int i=1; i<N+1; i++) {
        cin >> a;
        for (int j=0; j<a; j++) {
            cin >> b;
            nodes[i].push_back(b);
            nodes[b].push_back(i);
        }
    }

    int startSet = 1 << 1;

    // n (= i) 개 뽑을 때 dfs
    for (int i=0; i<N-1; i++) {
        dfs(1, pop[1], 1<<1, i);
    }

    if (mn == DEFAULT) {
        cout << -1 << endl;
    }
    else {
        cout << mn << endl;
    }

    return 0;
}
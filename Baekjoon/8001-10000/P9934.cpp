// 완전 이진 트리
// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

// It includes almost all header files for algorithm practice.
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

void setValue(int (**nodes), int (*v), int l, int r) {
    if (l == r) return;
    int c = (l + r) / 2;

    nodes[v[c]][0] = v[(l + c - 1) / 2];
    nodes[v[c]][1] = v[(c + 1 + r) / 2];

    setValue(nodes, v, l, c - 1);
    setValue(nodes, v, c + 1, r);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int K, M;
    int count = 0;
    int level = 0;
    int** nodes;
    int* v;

    cin >> K;

    M = (int)pow(2, K) - 1;

    v = new int[M];
    nodes = new int*[M];
    for (int i = 0; i < M; i++) {
        nodes[i] = new int[2];
    }
    for (int i = 0; i < M; i++) {
        fill_n(nodes[i], 2, -1);
        cin >> v[i];
        v[i] -= 1;
    }

    setValue(nodes, v, 0, M - 1);

    //bfs
    queue<int> queue;
    queue.push(v[(M - 1) / 2]);
    while (!queue.empty()) {
        int p = queue.front();
        queue.pop();
        count++;
        if (count % (int)pow(2, level) == 0) {
            if (level != 0) {
                cout << '\n';
            }
            level++;
        }
        cout << p + 1 << ' ';

        for (int i = 0; i < 2; i++) {
            if (nodes[p][i] == -1) {
                continue;
            }
            queue.push(nodes[p][i]);
        }
    }

    return 0;
}
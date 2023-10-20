// 영역 구하기
// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <vector>
#include <algorithm>
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

// x : N : horizonal
// y : M : vertical

int M, N, K;
bool map[101][101];
iip dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

iip add(const iip a, const iip b) {
    return {a.first+b.first, b.second+a.second};
}

void makeBlock(const int& a, const int& b, const int& c, const int& d) {
    FOR(i, a, c) {
        FOR(j, b, d) {
            map[i][j] = true;
        }
    }
}

int getAreaSize(int x, int y) {
    queue<iip> q;
    int size = 1;
    map[x][y] = true;
    q.push({x, y});

    while(q.empty() == false) {
        auto p = q.front();
        q.pop();
        
        for(auto d : dir) {
            iip c = add(p, d);
            if (c.first < 0 || c.first >= N || c.second < 0 || c.second >= M) {
                continue;
            }

            if (map[c.first][c.second] == false) {
                map[c.first][c.second] = true;
                q.push(c);
                size++;
            }
        }
    }
    return size;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> M >> N >> K;

    FOR(i, 0, K) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        makeBlock(a, b, c, d);
    }

    // FOR(i, 0, N) {
    //     FOR(j, 0, M) {
    //         cout << (map[i][j] ? 1 : 0) << ' ';
    //     }
    //     cout << endl;
    // }

    iv v;
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if (map[i][j] == false) {
                int s = getAreaSize(i, j);
                v.push_back(s);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    FOR(i, 0, v.size()) {
        cout << v[i] << ' ';
    }

    

    return 0;
}
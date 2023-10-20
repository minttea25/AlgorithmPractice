// 토마토
// https://www.acmicpc.net/problem/7569

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

class Dim3 {
public:
    Dim3(int x, int y, int z) : x(x), y(y), z(z) { }
    Dim3 operator+(const Dim3& other) 
    {
        return Dim3(x + other.x, y+other.y, z+other.z);
    }
    bool operator==(const Dim3& other) {
        return (x == other.x && y == other.y && z == other.z);
    }
public:
    int x, y, z;
};

const Dim3 dir[] = {
    Dim3(0, 0, 1),
    Dim3(0, 0, -1),
    Dim3(1, 0, 0),
    Dim3(-1, 0, 0),
    Dim3(0, 1, 0),
    Dim3(0, -1, 0)
};

constexpr int MAX = 101;
constexpr int RIPE_TAMATO = 1;
constexpr int EMPTY = -1;
constexpr int RAW_TOMATO = 0;

const Dim3 DUMMY(-1, -1, -1);

int box[MAX][MAX][MAX];
vector<Dim3> ripes;
int M, N, H;
int nRaws = 0;
int beRipe = 0;

int BFS() {
    queue<Dim3> q;
    int days = -1;

    for(auto d : ripes) {
        q.push(d);
    }
    q.push(DUMMY);

    while(q.empty() == false) {
        auto pop = q.front();
        q.pop();        
        
        if (pop == DUMMY) {
            days++;
            if (q.size() == 0) break;
            q.push(DUMMY);
            continue;
        }

        for(auto d : dir) {
            Dim3 xyz = pop + d;
            if (xyz.x <= 0 || xyz.x > N
                || xyz.y <= 0 || xyz.y > M
                || xyz.z <= 0 || xyz.z > H) continue;

            if (box[xyz.x][xyz.y][xyz.z] == RAW_TOMATO) {
                box[xyz.x][xyz.y][xyz.z] = RIPE_TAMATO;
                q.push(xyz);
                beRipe++;
            }
        }
    }

    return days;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> M >> N >> H;

    FOR_(h, 1, H) {
        FOR_(n, 1, N) {
            FOR_(m, 1, M) {
                cin >> box[n][m][h];
                if (box[n][m][h] == RIPE_TAMATO) ripes.push_back(Dim3(n, m, h));
                if (box[n][m][h] == RAW_TOMATO) nRaws++;
            }
        }
    }

    int days = BFS();

    if (nRaws == beRipe) {
        cout << days << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
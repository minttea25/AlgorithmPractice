// 적록색약
// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <vector>

// It includes almost all header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
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
typedef pair<short, short> ssp;

constexpr short R = 1;
constexpr short G = 2;
constexpr short B = 3;
constexpr short VISITED = -1;

constexpr ssp dir[4] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

short RGB[101][101];
short RB[101][101];

int ansA = 0, ansB = 0;
int N;

void dfs(ssp coords, short color) {
    RGB[coords.first][coords.second] = VISITED;

    for (ssp d : dir) {
        short x = coords.first + d.first;
        short y = coords.second + d.second;

        if (x <= 0 || x > N || y <= 0 || y > N) {
            continue;
        }

        if (RGB[x][y] != VISITED && RGB[x][y] == color) {
            dfs({x, y}, color);
        }
    }
}

void dfs2(ssp coords, short color) {
    RB[coords.first][coords.second] = VISITED;

    for (ssp d : dir) {
        short x = coords.first + d.first;
        short y = coords.second + d.second;

        if (x <= 0 || x > N || y <= 0 || y > N) {
            continue;
        }

        if (RB[x][y] != VISITED && RB[x][y] == color) {
            dfs2({x, y}, color);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    string s;
    char c;
    
    FOR_(i, 1, N) {
        cin >> s;
        FOR_(j, 0, s.length()) {
            c = s[j];
            switch (c)
            {
            case 'R':
                RGB[i][j+1] = R;
                RB[i][j+1] = R;
                break;
            case 'G':
                RGB[i][j+1] = G;
                RB[i][j+1] = R;
                break;
            case 'B':
                RGB[i][j+1] = B;
                break;
            default:
                break;
            }
        }
    }

    FOR_(i, 1, N) {
        FOR_(j, 1, N) {
            if (RGB[i][j] != VISITED) {
                dfs({i, j}, RGB[i][j]);
                ansA++;
            }
            if (RB[i][j] != VISITED) {
                dfs2({i, j}, RB[i][j]);
                ansB++;
            }
        }
    }

    cout << ansA << ' ' << ansB << endl;

    return 0;
}
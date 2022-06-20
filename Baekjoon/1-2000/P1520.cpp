// 내리막 길
// https://www.acmicpc.net/problem/1520

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

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

constexpr int MAX = 500+1;
constexpr ll DEFAULT = -1;

int n, m;
ll dp[MAX][MAX];
int input[MAX][MAX];
bool visited[MAX][MAX];

iip dir[4] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};


int dfs(int x, int y) {
    if (x==1 && y==1) {
        return 1;
    }

    if (dp[x][y] != DEFAULT) {
        return dp[x][y];
    }

    int rv = 0;

    for (iip d : dir) {
        int xx = x + d.first;
        int yy = y + d.second;
        if (x < 0 || xx> m || yy < 0 || yy > n) {
            continue;
        }

        if (!visited[xx][yy]&& input[xx][yy] > input[x][y]) {
            visited[xx][yy] = true;

            rv += dfs(xx, yy);

            visited[xx][yy] = false;
        }
    }
    dp[x][y] = rv;
    return rv;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int t;
    int idx = 0;

    cin >> m >> n;
    FOR_(i, 1, m) {
        FOR_(j, 1, n) {
            cin >> input[i][j];
        }
    }

    FOR(i, 0, m+1) {
        fill_n(dp[i], n+1, DEFAULT);
    }

    dp[m][n] = dfs(m, n);

    cout << dp[m][n] << endl;

    return 0;
}
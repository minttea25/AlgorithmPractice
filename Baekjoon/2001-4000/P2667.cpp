// 단지번호붙이기
// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

const int EMPTY = 0;
const int HOUSE = 1;
const int CHECKED = 2;

iip dir[] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int map[25][25];
iv connectedComponents;
int N;

int connectComponents(const int x, const int y) {
    int count = 1;
    map[x][y] = CHECKED;
    queue<iip> q;

    q.push({x, y});
    while(q.empty() == false) {
        auto node = q.front();
        q.pop();

        for(auto d : dir) {
            int xx = node.first+d.first;
            int yy = node.second+d.second;
            if (xx >= N || xx < 0 || yy >= N || yy < 0) continue;
            if (map[xx][yy] == HOUSE) {
                map[xx][yy] = CHECKED;
                q.push({xx, yy});
                count++;
            }
        }
    }

    return count;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;
    FOR(i, 0, N) {
        string line;
        cin >> line;
        FOR(j, 0, N) {
            if (line[j] == '0') {
                map[i][j] = EMPTY;
            }
            else {
                map[i][j] = HOUSE;
            }
        }
    }

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if (map[i][j] == HOUSE) {
                connectedComponents.push_back(connectComponents(i, j));
            }
        }
    }
    sort(connectedComponents.begin(), connectedComponents.end());

    cout << connectedComponents.size() << endl;
    FOR(i, 0, connectedComponents.size()) {
        cout << connectedComponents[i] << endl;
    }

    return 0;
}
// 쿼드트리
// https://www.acmicpc.net/problem/1992

#include <iostream>
#include <vector>
#include <algorithm>

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

bool image[64][64];
int N;

string checkArea(const int size, int x, int y) {
    // check base
    if (size == 1) {
        if (image[x][y] == 0) return "0";
        else return "1";
    }

    bool flag = true;
    int t = image[x][y];
    FOR(i, x, x+size) {
        FOR(j, y, y+size) {
            if (t != image[i][j])  {
                flag = false;
                break;
            }
        }
        if (flag == false) break;
    }

    if (flag == true) {
        if (t == 0) return "0";
        else return "1";
    }

    return "(" 
    + checkArea(size/2, x, y) 
    + checkArea(size/2, x+size/2, y)
    + checkArea(size/2, x, y+size/2)
    + checkArea(size/2, x+size/2, y+size/2)
    + ")";    
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    FOR(i, 0, N) {
        string s;
        cin >> s;
        FOR(j, 0, N) {
            auto t = s[j];
            if (t == '0') {
                image[j][i] = 0;
            }
            else {
                image[j][i] = 1;
            }
        }
    }

    cout << checkArea(N, 0, 0) << endl;

    return 0;
}
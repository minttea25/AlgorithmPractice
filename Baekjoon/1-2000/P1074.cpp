// Z
// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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

int N, r, c;

int getAns(const int size, int x, int y) {
    if (size == 1) {
        return 0;
    }

    if (x < size/2 && y < size/2) {
        return getAns(size/2, x, y);
    }
    else if (x >= size/2 && y < size/2) {
        return 1*(size/2 * size/2) + getAns(size/2, x - size/2, y);
    }
    else if (x < size/2 && y >= size/2) {
        return 2 * (size/2 * size/2) + getAns(size/2, x, y - size/2);
    }
    else {
        return 3 * (size/2 * size/2) + getAns(size/2, x - size/2, y - size/2);
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> r >> c;

    cout << getAns(pow(2, N), c, r) << endl;

    return 0;
}
// 음하철도 구구팔
// https://www.acmicpc.net/problem/1393

#include <iostream>
#include <vector>
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

double dist(iip a, iip b) {
    return sqrt(pow(b.second - a.second, 2) + pow(b.first - a.first, 2));
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int tx, ty;
    int x, y, dx, dy;

    cin >> tx >> ty >> x >> y >> dx >> dy;

    double nowDist = dist({tx, ty}, {x, y});
    double after1Dist = dist({tx, ty}, {x+dx, y+dy});

    if (nowDist < after1Dist) {
        cout << x << ' ' << y << endl;
        return 0;
    }

    if (dx==0 && dy==0) {
        cout << x << ' ' << y << endl;
        return 0;
    }
    else if (dy == 0) {
        cout << tx << ' ' << y << endl;
        return 0;
    }
    else if (dx == 0) {
        cout << x << ' ' << ty << endl;
        return 0;
    }

    double a1 = (double)dy / dx;
    double a2 = -1 * (double)dx / dy; 

    double b1 = (double) y - a1*x; // -> y = a1*x + bias
    double b2 = (double) ty - a2*tx;

    double xx = (b2 - b1) / (a1 - a2);
    double yy = (a1*b2 - a2*b1) / (a1 - a2);

    cout << xx << ' ' << yy << endl;

    return 0;
}
// PIZZA ALVOLOC
// https://www.acmicpc.net/problem/12781

#include <iostream>
#include <vector>
#include <algorithm>

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

// ccw algorithm
// For consecutive points a, b and c in a 2d plane,
// return positive if clockwise,
// return negative if counterclockwise
// return 0 if on a straight line.
ll ccw(iip a, iip b, iip c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    iip a, b, c, d;

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

    // make a line with a and b
    // then, check ccw
    // if a-c-b is clockwise -> a-d-b should be counter-clockwise
    // if a-c-b is counter-clockwise -> a-d-b soule be clockwise

    int con1 = ccw(a, c, b);
    int con2 = ccw(a, d, b);

    if ((con1 > 0 && con2 < 0) || (con1 < 0 && con2 > 0)) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
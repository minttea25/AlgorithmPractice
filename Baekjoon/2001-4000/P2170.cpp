// 선 긋기
// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost header files for algorithm practice.
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

typedef iip line;
line lines[1000001];

int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int sum = 0;
    
    cin >> N;
    FOR(i, 0, N) {
        cin >> lines[i].first >> lines[i].second;
    }

    sort(lines, lines+N); // sort by first element

    int x, y;

    x = -1000000000;
    y = -1000000000;

    FOR(i, 0, N) {
        if (lines[i].first <= y) {
            y = max(y, lines[i].second);
        }
        else {
            sum += (y-x);
            x = lines[i].first;
            y = lines[i].second;
        }
    }

    sum += (y-x);

    cout << sum << endl;

    return 0;
}
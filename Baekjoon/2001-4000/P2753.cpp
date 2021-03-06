// 윤년
// https://www.acmicpc.net/problem/2753

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// It includes almost all header files for algorithm practice.
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

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int year;
    cin >> year;

    cout << ((year%4==0&&year%100!=0) || year%400==0) ? 1 : 0 << endl;

    return 0;
}
// 소수
// https://www.acmicpc.net/problem/2581

#include <iostream>
#include <vector>
#include <math.h>

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

int N, M;

bool isPrimeNumber(int n) {
    if (n == 0 || n == 1) return false;

    FOR_(i, 2, floor(sqrt(n))) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> M >> N;

    int sum = 0;
    int mn = 1000000000;

    FOR_(i, M, N) {
        if (isPrimeNumber(i)) {
            sum += i;
            mn = min(mn, i);
        }
    }

    if (sum == 0) cout << -1 << endl;
    else {
        cout << sum << endl;
        cout << mn << endl;
    }

    return 0;
}
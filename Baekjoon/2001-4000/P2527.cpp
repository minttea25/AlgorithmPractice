// 직사각형
// https://www.acmicpc.net/problem/2527

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

// a = A[0]
// b = A[1]
// c = A[2]
// d = A[3]

// e = B[0]
// f = B[1]
// g = B[2]
// h = B[3]

char checkSquare(const int* A, const int* B) {
    // a==g || c==e
    if (A[0] == B[2] || A[2] == B[0]) {
        // b==h || d==f
        if (A[1] == B[3] || A[3] == B[1]) {
            return 'c';
        }

        // h<b || d<f 
        if (B[3] < A[1] || A[3] < B[1]) {
            return 'd';
        }
        return 'b';
    }
    // b==h || d==f
    else if (A[1] == B[3] || A[3]==B[1]) {
        // g<a || c<e
        if (B[2]<A[0] || A[2]<B[0]) {
            return 'd';
        }
        return 'b';
    }

    // check d
    // d<f || h<b || c<e || g<a
    if (A[3] < B[1] || B[3]<A[1] || A[2]<B[0] || B[2]<A[0]) {
        return 'd';
    }

    return 'a';
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int T = 4;
    int A[4];
    int B[4];

    for (int i=0; i<T; i++) {
        for(int j=0; j<4; j++) {
            cin >> A[j];
        }
        for(int j=0; j<4; j++) {
            cin >> B[j];
        }
        cout << checkSquare(A, B) << endl;
    }

    return 0;
}
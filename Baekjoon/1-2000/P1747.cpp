// 소수&팰린드롬
// https://www.acmicpc.net/problem/1747

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

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

int N;

bool isPrime(int n) {
    FOR_(i, 2, (int)sqrt(n)) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(int n) {
    string s = to_string(n);
    int l = s.length();
    
    FOR(i, 0, l/2) {
        if (s[i] != s[l-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N;

    if (N == 1) {
        cout << 2 << endl;
        return 0;
    }

    FOR(i, N, 100000000) {
        if (isPrime(i) && isPalindrome(i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
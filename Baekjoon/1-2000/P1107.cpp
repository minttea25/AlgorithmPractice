// 리모컨
// https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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

constexpr int CHANNEL = 100;

int N;
bool broken[10] = {0, };
int M;

// cf: to_string은 시간이 매우 오래걸림!
// to_string으로 했을 때 16ms
// 아래와 같이 나눗셈만 이용했을 때는 0ms
// (acmicpc 기준)
bool checkPushable(int n) {
    if (n < 0) return false;
    do {
        if (broken[n%10]) return false;
        n /= 10;
    } while(n != 0);
    return true;
}

int move(int des) {
    for(int i=0; ; ++i) {
        // 반드시 - 먼저 확인해야 작은 값을 가져올 수 있음
        if (checkPushable(des-i) == true) {
            return to_string(des-i).size() + i;
        }
        else if (checkPushable(des+i) == true) {
            return to_string(des+i).size() + i;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    FOR(i, 0, M) {
        int t;
        cin >> t;
        broken[t] = true;
    }

    if ((int)abs(CHANNEL - N) <= 3 || M == 10) {
        cout << (int)abs(CHANNEL - N) << endl;
    }
    else if (M == 0) {
        cout << min((int)abs(CHANNEL - N), (int)to_string(N).size()) << endl;
    }
    else {
        cout << min(move(N), (int)abs(CHANNEL - N)) << endl;
    }

    return 0;
}
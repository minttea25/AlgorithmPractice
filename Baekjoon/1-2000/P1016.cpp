// 제곱 ㄴㄴ 수
// https://www.acmicpc.net/problem/1016

#include <iostream>

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

using namespace std;

typedef long long ll;
typedef pair<int, int> iip;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long min, max;
    int count = 0;
    long long n;
    bool* sieve;

    cin >> min;
    cin >> max;

    sieve = new bool[max-min+1];
    fill_n(sieve, max-min+1, false);

    for (n=2; n*n<=max; n++) {
        long long sh = min / (n*n);

        // min을 넘지 않는 최댓값 구하기
        if (sh*n*n < min) {
            // min을 넘지 않으면 (sh+1) * (n^2) 은 min을 넘는 최솟값이다.
            sh++;
        }
        // (sh) 부터 n^2 씩 늘려가며 max 까지 확인
        for (ll i=sh*n*n; i<=max; i+=(n*n)) {
            // i-min은 int type(범위)를 넘지 않음 (i-min -> long long, but it is in int range)
            if (!sieve[i-min]) {
                count++;
                sieve[i-min] = true; // 확인 표시
            }
        }
    }
    cout << max-min+1-count;
    
    return 0;
}
// 분산처리
// https://www.acmicpc.net/problem/1009

#include <iostream>
#include <vector>
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

constexpr int COM = 10;
vector<iv> map = { 
    {10},
    {1},
    {6, 2, 4, 8},
    {1, 3, 9, 7},
    {6, 4},
    {5},
    {6},
    {1, 7, 9, 3},
    {6, 8, 4, 2},
    {1, 9}
    };

int n;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b;

    cin >> n;
    FOR(i, 0, n) {
        cin >> a >> b;

        cout << map[a%COM][b%map[a%COM].size()] << endl;
    }

    return 0;
}
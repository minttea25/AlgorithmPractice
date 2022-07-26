// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003

#include <vector>
#include <iostream>

using namespace std;

#define DUMMY -1
#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define FOR_(i, s, e) for (int i=s; i<=e; i++)
#define iFOR(i, s, e) for(int i=s; i>e; i--)
#define iFOR_(i, s, e) for (int i=s; i>=e; i--)

constexpr int MAX = 1000000001;
constexpr int MIN = -1000000001;

typedef vector<int> iv;

int n;
iv lastInput;

iv inputs; // int inputs[MAX];
iv lis;// int lis[MAX];

iv invInputs;// int invInputs[MAX];
iv tInvLis;// int tInvLis[MAX];
iv invLis;// int invLis[MAX];

iv lMax;// int lMax[MAX];

int mx;

void LIS(iv& in, iv& out, int n) {
    lastInput.clear();

    vector<int>::iterator it;
    lastInput.push_back(MIN); // we don't use value at index=0

    out.push_back(MIN);

    for (int i = 1; i <= n; i++) {
        if (lastInput.back() < in[i]) {
            lastInput.push_back(in[i]);
        }
        // 크거나 같은 값 중 가장 작은 수를 가져옴
        it = lower_bound(lastInput.begin(), lastInput.end(), in[i]);
        *it = in[i];
        out.push_back(it - lastInput.begin());

        mx = max(mx, out[i]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    mx = -1;

    int ti;

    cin >> n;
    inputs.push_back(DUMMY);
    for (int i = 1; i <= n; i++) {
        cin >> ti;
        inputs.push_back(ti);
    }

    LIS(inputs, lis, n);

    invInputs.assign(n + 1, DUMMY);
    FOR(i, 1, n + 1) {
        invInputs[n - i + 1] = MAX - inputs[i];
    }
    LIS(invInputs, tInvLis, n);
    invLis.assign(n + 1, DUMMY);
    FOR(i, 1, n + 1) {
        invLis[n - i + 1] = tInvLis[i];
    }

    lMax.push_back(MIN);
    FOR(i, 1, n + 1) {
        if (lis[i] + invLis[i] == mx + 1) {
            lMax.push_back(max(lMax[i - 1], inputs[i]));
        }
        else {
            lMax.push_back(lMax[i - 1]);
        }
    }

    // print ans

    cout << mx << endl;

    int prev = lMax[0];
    FOR(i, 1, n + 1) {
        if (prev != lMax[i]) {
            prev = lMax[i];
            cout << lMax[i] << ' ';
        }
    }
    cout << endl;


    return 0;
}

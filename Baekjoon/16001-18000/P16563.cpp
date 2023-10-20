// 여러운 소인수 분해
// https://www.acmicpc.net/problem/16563

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> calcMinFactors(const int n) {
    vector<int> minFactor(n+1);

    minFactor[0] = minFactor[1] = -1;

    for(int i=2; i<=n; ++i) minFactor[i] = i;

    int t = int(sqrt(n));
    for(int i=2; i<=t; ++i) {
        if (minFactor[i] == i) {
            for(int j=i*i; j<=n; j+=i) {
                if (minFactor[j] == j) minFactor[j] = i;
            }
        }
    }

    return minFactor;
}

vector<int> getFactors(vector<int>& minFactor, int n) {
    vector<int> ret;

    while(n > 1) {
        ret.push_back(minFactor[n]);
        n /= minFactor[n];
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int tc;
    cin >> tc;

    int mx = 0;
    vector<int> inputs;
    for(int i=0; i<tc; ++i) {
        int t;
        cin >> t;
        inputs.push_back(t);
        mx = max(t, mx);
    }

    auto minFactor = calcMinFactors(mx);

    for(int i=0; i<tc; ++i) {
        auto factors = getFactors(minFactor, inputs[i]);
        for(int j=0; j<factors.size(); ++j) cout << factors[j] << ' ';
        cout << '\n';
    }

    return 0;
}
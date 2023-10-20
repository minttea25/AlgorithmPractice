// 마법의 약
// p.507

#include <iostream>
#include <vector>

using namespace std;

constexpr int gcd(const int a, const int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int getAlpha(const vector<int>& r) {
    if (r.size()==1) return r[0];
    int t = r[0];
    for(int i=1; i<r.size(); ++i) t = gcd(r[i], t);
    return t;
}

vector<int> solve(const vector<int>& r, const vector<int>& p) {
    const int alpha = getAlpha(r);

    int mxIdx = 0;
    double mx = 0;
    for(int i=0; i<r.size(); ++i) {
        double t = static_cast<double>(p[i]) / r[i];
        if (mx > t) {
            mx = t;
            mxIdx = i;
        }
    }

    int idx = 0;
    const int t = r[mxIdx] / alpha;
    while (true) {
        if ((p[mxIdx] + idx) % t == 0) break;
        else idx++;
    }
    const int beta = (p[mxIdx] + idx) / t;

    vector<int> ret;
    for(int i=0; i<r.size(); ++i) ret.push_back(beta * r[i] / alpha - p[i]);
    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int tc;
    int n;
    vector<int> r;
    vector<int> p;

    cin >> tc;

    int t;
    for(int i=0; i<tc; ++i) {
        r.clear();
        p.clear();

        cin >> n;
        for(int j=0; j<n; ++j) {
            cin >> t;
            r.push_back(t);
        }
        for(int j=0; j<n; ++j) {
            cin >> t;
            p.push_back(t);
        }

        auto ans = solve(r, p);
        for(int j=0; j<ans.size(); ++j) cout << ans[j] << ' ';
        cout << '\n';
    }

    return 0;
}
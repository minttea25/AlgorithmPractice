#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> calcMinFactor(const int n) {
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

vector<int> getNumberOfFactors(int N) {
    vector<int> minFactor = calcMinFactor(N);

    vector<int> minFactorPower(N+1); // a (exponent of minFactor[i])
    vector<int> factors(N+1); // the number of factors 

    factors[1] = 1; // factors[0] does not appear

    for(int n=2; n<=N; ++n) {
        if (minFactor[n] == n) {  // = if n is a prime number 
            minFactorPower[n] = 1; // => expressed of p^1 (Note: n is a prime number)
            factors[n] = 2; // because n is a prime number.
        }
        else {
            // A_i = factors[i]
            // p = minFactor[n];
            // a = minFactorPower[n]
            // A_n = A_(p/n) * (a+1) / a = A_m * (a+1) / a

            int p = minFactor[n];
            int m = n / p; // divide once by p
            if (p != minFactor[m]) {// if m can not be divided by p, the a will be 1
                minFactorPower[n] = 1;
            }
            else { // if i = p^a * Q => n = p^(a+1) * Q when (a > 0)
                minFactorPower[n] = minFactorPower[m] + 1;
            }

            int a = minFactorPower[n];
            factors[n] = factors[m] * (a + 1) / a;
        }
    }

    return factors;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int tc;
    cin >> tc;

    vector<int> ans = getNumberOfFactors(10'000'000);

    for(int i=0; i<tc; ++i) {
        int n, lo, hi;
        cin >> n >> lo >> hi;

        int cnt = 0;
        for (int j=lo; j<=hi; ++j) {
            if (n == ans[j]) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
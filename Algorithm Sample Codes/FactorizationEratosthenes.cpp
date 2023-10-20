#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void eratosthenes(vector<int>& minFactor, int n) {
    minFactor[0] = minFactor[1] = -1; // except 0 and 1

    for(int i=2; i<=n; ++i) minFactor[i] = i;

    int sqrtn = int(sqrt(n));

    for(int i=2; i<=sqrtn; ++i) {
        if (minFactor[i] == i) {
            for (int j=i*i; j<=n; j+=i) {
                // 아직 약수를 본 적 없는 숫자인 경우 i
                if (minFactor[j] == j) minFactor[j] = i;
            }
        }
    }
}

vector<int> factor(vector<int>& minFactor, int n) {
    vector<int> ret;

    // n이 1이 될 때까지 가장 작은 소인수로 나누기 반복
    while(n > 1) {
        ret.push_back(minFactor[n]);
        n /= minFactor[n];
    }

    return ret;
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    eratosthenes(v, n);

    auto factors = factor(v, n);

    for(int i=0; i<factors.size(); ++i) {
        cout << factors[i] << ' ';
    }
    cout << endl;


    return 0;
}
// p.240 원주율 외우기

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

constexpr int INF = 987654321;//std::numeric_limits<int>().max();

int memoi[10002] = {0, };

int getDifficulty(int a, int b, vector<int>& arr) {
    // [a, b]

    if (b-a <= 0) return 0;

    string s(b-a+1, '0');
    int size = s.size();

    for(int i=0; i<size; ++i) s[i] = arr[a+i] + '0';

    //cout << s << endl;

    bool arith = true;
    for(int i=0; i<size-1; ++i) {
        if (s[i+1] - s[i] != s[1] - s[0]) {
            arith = false;
            break;
        }
    }

    if (arith == true && s[1] - s[0] == 0) return 1;
    if (arith == true && (s[1] - s[0] == 1 || s[1] - s[0] == -1)) return 2;

    bool alter2 = true;
    for(int i=0; i<size; ++i) {
        if (s[i] != s[i%2]) {
            alter2 = false;
            break;
        }
    }

    if (alter2 == true) return 4;
    if (arith == true) return 5;

    return 10;
}

// [0, len-1] 까지의 최솟값
int memorize(int len, vector<int>& v) {
    int& ret = memoi[len-1];
    if (ret != -1) return ret;

    ret = 987654321;
    if (len >= 3) ret = min(ret, memorize(len-3, v) + getDifficulty(len-3, len-1, v));
    if (len >= 4) ret = min(ret, memorize(len-4, v) + getDifficulty(len-4, len-1, v));
    if (len >= 5) ret = min(ret, memorize(len-5, v) + getDifficulty(len-5, len-1, v));

    return ret;
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int j=0; j<t; ++j) {
        for(int i=0; i<10002; ++i) memoi[i] = -1;

        int n;
        cin >> n;
        vector<int> v;

        for(int i=0; i<n; ++i) {
            int t;
            cin >> t;
            v.push_back(t);
        }

        cout << memorize(n, v) << endl;
    }

    return 0;
}
#include <vector>
#include <iostream>

//#define PRINT_VECTOR(v) for(int i=0; i<v.size(); ++i) std::cout << v[i] << ' '; std::cout << '\n';

using namespace std;

constexpr int UNIT = 3;
constexpr int MAX_SWITCHES = 10;
constexpr int INF = 1'000'000'000;

constexpr int MAX_CLOCKS = 16;

vector<int> switches[MAX_SWITCHES] = {
    {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12},
    {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}
};

bool checkClocks(vector<int>& clocks) {
    for (int i=0; i<clocks.size(); ++i) {
        if (clocks[i] != 0) return false;
    }
    return true;
}

void pushSwitch(const int switchId, vector<int>& clocks) {
    auto swt = switches[switchId];
    for(int i=0; i<swt.size(); ++i) {
        clocks[swt[i]] = (clocks[swt[i]] + 1) % (UNIT + 1);
    }
}

int solve(const int switchId, vector<int>& clocks) {
    if (switchId == MAX_SWITCHES) return checkClocks(clocks) ? 0 : INF;

    int ret = INF;
    for(int i=0; i<=UNIT; ++i) {
        ret = min(solve(switchId + 1, clocks) + i, ret);
        pushSwitch(switchId, clocks);
    }

    return ret;
}

int main() {
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    vector<int> clocks;
    for(int i=0; i<MAX_CLOCKS; ++i) {
        int t;
        cin >> t;
        clocks.push_back((t / UNIT) % (UNIT + 1));
    }

    cout << solve(0, clocks) << endl;

    return 0;
}

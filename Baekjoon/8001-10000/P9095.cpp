// 1, 2, 3 더하기
// https://www.acmicpc.net/problem/9095

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX = 3;

void search(const int n, const int mx, int& count) {
    // base case
    if (n == 0) 
    {
        count++;
        return;
    }

    for (int i=1; i<=MAX; ++i)
    {
        if (n - i >= 0) search(n - i, mx, count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc > 0) 
    {
        int n;
        cin >> n;

        int count = 0;
        search(n, n, count);
        cout << count << '\n';

        tc --;
    }

    return 0;
}
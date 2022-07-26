// 총알의 속도
// https://www.acmicpc.net/problem/18017

#include <iostream>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    double a, b, c=299792458.0;
    cin >> a >> b;
    cout.precision(30);
    cout << (a + b) / (1 + (a * b) / (c * c)) << endl;

    return 0;
}
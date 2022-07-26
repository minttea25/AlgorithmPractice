#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> iip;

#define endl '\n'

// ccw algorithm
// For consecutive points a, b and c in a 2d plane,
// return positive if clockwise,
// return negative if counterclockwise
// return 0 if on a straight line.
ll ccw(iip a, iip b, iip c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

string printCCW_string(int v) {
    if (v > 0) {
        return "clockwise";
    }
    else if (v < 0) {
        return "counter-clockwise";
    }
    // v == 0
    else {
        return "on a line";
    }
}

int main() {
    iip A = {0, 0};
    iip B = {1, 1};
    iip C = {0, 1};
    iip D = {1, 0};
    iip E = {2, 2};

    string out;

    int ACB = ccw(A, C, B);
    int ADB = ccw(A, D, B);
    int ABE = ccw(A, B, E);

    cout << "*\t*\tE" << endl;
    cout << "C\tB\t*" << endl;
    cout << "A\tD\t*" << endl;

    cout << "A-C-B : " << printCCW_string(ACB) << endl;
    cout << "A-D-B : " << printCCW_string(ADB) << endl;
    cout << "A-B-E : " << printCCW_string(ABE) << endl;
}
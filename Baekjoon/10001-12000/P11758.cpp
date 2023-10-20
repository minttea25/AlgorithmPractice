// CCW
// https://www.acmicpc.net/problem/11758

#include <iostream>

using namespace std;

enum CCW 
{
    ClockWise = -1, CounterClockWise = 1, Parallel = 0
};

struct vector2
{
public:
    double x, y;
    vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    vector2 operator-(const vector2& rhs) const
    {
        return vector2(x - rhs.x, y - rhs.y);
    }

    double cross(const vector2& v)
    {
        return x * v.y - y * v.x;
    }
};

CCW ccw(const vector2& a, const vector2& b, const vector2& c)
{
    double angle = (c - a).cross(c - b);
    if (angle > 0) return CCW::CounterClockWise;
    else if (angle < 0) return CCW::ClockWise;
    else return CCW::Parallel;

}

int main() {
    cout.sync_with_stdio(0);
    cin.sync_with_stdio(0);

    int x, y;
    vector2 a, b, c;

    cin >> x >> y;
    a.x = x; a.y = y;

    cin >> x >> y;
    b.x = x; b.y = y;

    cin >> x >> y;
    c.x = x; c.y = y;

    CCW ret = ccw(a, b, c);
    cout << ret << '\n';

    return 0;
}
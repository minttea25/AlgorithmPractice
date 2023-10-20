// 평행사변형
// https://www.acmicpc.net/problem/1064

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct vector2 
{
public:
    double x, y;
    vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    vector2 operator-(const vector2& rhs) const
    {
        return vector2(x - rhs.x, y - rhs.y);
    }

    double norm() const
    {
        return hypot(x, y);
    }

    double cross(const vector2& rhs) const
    {
        return x * rhs.y - y * rhs.x;
    }

    double distanceToPoint(const vector2& other) const
    {
        return (*this - other).norm();
    }
};

bool isOnSameLine(const vector2& a, const vector2& b, const vector2& c) 
{
    double cross = (b - a).cross(c - a);
    return cross == 0;
}


bool getLength(const vector2& a, const vector2& b, const vector2& c, double& maxLen, double& minLen) 
{
    if (isOnSameLine(a, b, c) == true) return false;

    double mx = 0;
    double mn = 10000000;

    const double ab = a.distanceToPoint(b);
    const double ac = a.distanceToPoint(c);
    const double bc = b.distanceToPoint(c);
    
    const double bac = ab + ac;
    const double abc = ab + bc;
    const double acb = ac + bc;

    if (bac > abc) 
    {
        mx = bac;
        mn = abc;
    } 
    else 
    {
        mx = abc;
        mn = bac;
    }

    if (acb > mx) 
    {
        mx = acb;
    } 
    else if (acb < mn) 
    {
        mn = acb;
    }
    
    maxLen = mx * 2;
    minLen = mn * 2;

    return true;
}

int main() 
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector2 a;
    vector2 b;
    vector2 c;

    double x, y;

    cin >> x >> y;
    a.x = x; a.y = y;

    cin >> x >> y;
    b.x = x; b.y = y;

    cin >> x >> y;
    c.x = x; c.y = y;

    double mn;
    double mx;

    cout.precision(15);

    if (getLength(a, b, c, mx, mn) == true) 
    {
        cout << mx - mn << endl;
    }
    else
    {
        cout << -1.0 << endl;
    }

    return 0;
}
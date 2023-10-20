// 다각형의 면적
// https://www.acmicpc.net/problem/2166

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct vector2
{
public:
    double x,  y;

    vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    vector2 operator-(const vector2& rhs) const 
    {
        return vector2(x - rhs.x, y - rhs.y);
    }

    double cross(const vector2& rhs) const
    {
        return x * rhs.y - y * rhs.x;
    }
};

int main() 
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    vector<vector2> points;
    int n;
    cin >> n;

    for(int i=0; i<n; ++i) 
    {
        double x, y;
        cin >> x >> y;
        points.push_back(vector2(x, y));
    }

    double ret = 0;
    for(int i=1; i<n-1; ++i) 
    {
        ret += (points[i] - points[0]).cross(points[i+1] - points[0]) * 0.5;
    }

    cout << fixed << setprecision(1) << fabs(ret) << endl;

    return 0;
}

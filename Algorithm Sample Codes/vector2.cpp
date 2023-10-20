#pragma once

#include <cmath>
#include <limits>
#include <algorithm>
#include <ostream>

const double PI = 2.0 * acos(0.0);
const double EPSILON = std::numeric_limits<double>::epsilon();

struct vector2
{
public:
	double x, y;

	explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	
	/*Basic Operations*/

	bool operator==(const vector2& rhs) const;
	bool operator<(const vector2& rhs) const;
	vector2 operator+(const vector2& rhs) const;
	vector2 operator-(const vector2& rhs) const;
	vector2 operator*(const double rhs) const;



	/*vector2 Properties*/

	// return length of vector
	double norm() const;
	// return unit vector (exception about zero-vector)
	vector2 normalize() const;
	// inner product
	double dot(const vector2& rhs) const;
	// cross product
	double cross(const vector2& rhs) const;
	// return a vector projected to rhs
	vector2 project(const vector2& rhs) const;
	// return the angle measured counterclockwise(ccw) from the positive x-axis direction to it
	double polar() const;


	friend std::ostream& operator<<(std::ostream& os, const vector2& v);



	/*Global Functions*/

	friend double dot(const vector2& v1, const vector2& v2);
	friend double cross(const vector2& v1, const vector2& v2);
	friend double norm(const vector2& v);
	friend vector2 normalize(const vector2& v);
	friend vector2 project(const vector2& v1, const vector2& v2);
	friend double polar(const vector2& v);

	// return the theta of v1 and v2
	friend double angle(const vector2& v1, const vector2& v2);
	// return true if v1 and v2 is orthogonal and false otherwise;
	friend bool isOrthogonal(const vector2& v1, const vector2& v2);
	// return distance between two points
	friend double distance(const vector2& p1, const vector2& p2);
	// directionality of vector; return positive if b is counterclockwise from a, negative if clockwise, and 0 if parallel, based on (0, 0)
	friend double ccw(const vector2& v1, const vector2& v2);
	// directionality of vector; return positive if b is counterclockwise from a, negative if clockwise, and 0 if parallel, based on p
	friend double ccw(const vector2& p, const vector2& v1, const vector2& v2);
	// for the line passing a and b and the line passing c and d, return false if they are parallel, and true otherwise, and assign the intersection point of them to points.
	friend bool lineIntersection(const vector2& a, const vector2& b, const vector2& c, const vector2& d, vector2& points);
	// return the perpendicular foot drawn from point p for the line passing two point a and b.
	friend vector2 perpendicularFoot(const vector2& p, const vector2& a, const vector2& b);
	// return the distance between the point p and the line passing two points a and b.
	friend double pointToLine(const vector2& point, const vector2& a, const vector2& b);



	friend bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& points);
	friend bool inBoundingRectangle(vector2 p, vector2 a, vector2 b);
	friend bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& points);
	friend bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d);
};

std::ostream& operator<<(std::ostream& os, const vector2& v)
{
	os << "vector2(" << v.x << ", " << v.y << ")";
	return os;
}

bool vector2::operator==(const vector2& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

bool vector2::operator<(const vector2& rhs) const
{
	return x != rhs.x ? x < rhs.x : y < rhs.y;
}

vector2 vector2::operator+(const vector2& rhs) const
{
	return vector2(x + rhs.x, y + rhs.y);
}

vector2 vector2::operator-(const vector2& rhs) const
{
	return vector2(x - rhs.x, y - rhs.y);
}

vector2 vector2::operator*(const double rhs) const
{
	return vector2(x * rhs, y * rhs);
}

double vector2::norm() const
{
	return hypot(x, y);
}

vector2 vector2::normalize() const
{
	return vector2(x / norm(), y / norm());
}

double vector2::dot(const vector2& rhs) const
{
	return x * rhs.x + y * rhs.y;
}

double vector2::cross(const vector2& rhs) const
{
	return x * rhs.y - y * rhs.x;
}

vector2 vector2::project(const vector2& rhs) const
{
	vector2 r = rhs.normalize();
	return r * r.dot(*this);
}

double vector2::polar() const
{
	return fmod(atan2(y, x) + 2 * PI, 2 * PI);
}

double dot(const vector2& v1, const vector2& v2)
{
	return v1.dot(v2);
}

double cross(const vector2& v1, const vector2& v2)
{
	return v1.cross(v2);
}

double norm(const vector2& v)
{
	return v.norm();
}

vector2 normalize(const vector2& v)
{
	return v.normalize();
}

vector2 project(const vector2& v1, const vector2& v2)
{
	return v1.project(v2);
}

double polar(const vector2& v)
{
	return v.polar();
}

double angle(const vector2& v1, const vector2& v2)
{
	return acos(v1.dot(v2) / (v1.norm() * v2.norm()));
}

bool isOrthogonal(const vector2& v1, const vector2& v2)
{
	return v1.dot(v2) == 0;
}

double distance(const vector2& p1, const vector2& p2)
{
	return (p1 - p2).norm();
}

double ccw(const vector2& v1, const vector2& v2)
{
	return v1.cross(v2);
}

double ccw(const vector2& p, const vector2& v1, const vector2& v2)
{
	return ccw(v1 - p, v2 - p);
}

bool lineIntersection(const vector2& a, const vector2& b, const vector2& c, const vector2& d, vector2& intersection)
{
	double det = (b - a).cross(d - c);
	if (fabs(det) < EPSILON) return false;

	intersection = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

vector2 perpendicularFoot(const vector2& point, const vector2& a, const vector2& b)
{
	return a + (point - a).project(b - a);
}

double pointToLine(const vector2& point, const vector2& a, const vector2& b)
{
	return (point - perpendicularFoot(point, a, b)).norm();
}

bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& points)
{
	if (b < a) std::swap(a, b);
	if (d < c) std::swap(c, d);

	// 한 직선 위에 없거나 두 선분이 겹치지 않는 경우
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	// 교차점 찾기
	if (a < c) points = c;
	else points = a;
	return true;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
{
	if (b < a) std::swap(a, b);
	return p == a || p == b || (a < p&& p < b);
}

bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& points)
{
	if (lineIntersection(a, b, c, d, points) == false) return parallelSegments(a, b, c, d, points);

	// p 가 두 선분에 포함되어 있는 경우
	return inBoundingRectangle(points, a, b) && inBoundingRectangle(points, c, d);
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d)
{
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	// 두 선분이 한 직선 위에 있거나 겹치는 경우
	if (ab == 0 && cd == 0)
	{
		if (b < a) std::swap(a, b);
		if (d < c) std::swap(c, d);
		return !(b < c || d < a);
	}

	return ab <= 0 && cd <= 0;
}


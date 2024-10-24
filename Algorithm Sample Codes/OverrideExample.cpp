#include <iostream>

class Vector2 {
public:
    int x, y;

    // 기본 생성자
    Vector2() : x(0), y(0) {}

    // 매개변수 생성자
    Vector2(int x, int y) : x(x), y(y) {}

    // 복사 생성자
    Vector2(const Vector2& other) : x(other.x), y(other.y) {
        std::cout << "Copy Constructor called!" << std::endl;
    }

    // 이동 생성자
    Vector2(Vector2&& other) noexcept : x(other.x), y(other.y) {
        other.x = 0;
        other.y = 0;
        std::cout << "Move Constructor called!" << std::endl;
    }

    // 복사 대입 연산자
    Vector2& operator=(const Vector2& other) {
        if (this == &other) return *this;  // 자기 자신을 대입하는 경우 처리
        x = other.x;
        y = other.y;
        std::cout << "Copy Assignment called!" << std::endl;
        return *this;
    }

    // 이동 대입 연산자
    Vector2& operator=(Vector2&& other) noexcept {
        if (this == &other) return *this;  // 자기 자신을 대입하는 경우 처리
        x = other.x;
        y = other.y;
        other.x = 0;
        other.y = 0;
        std::cout << "Move Assignment called!" << std::endl;
        return *this;
    }

    // 사칙연산자 오버로딩
    // 덧셈 연산자
    Vector2 operator+(const Vector2& rhs) const {
        return Vector2(x + rhs.x, y + rhs.y);
    }

    // 뺄셈 연산자
    Vector2 operator-(const Vector2& rhs) const {
        return Vector2(x - rhs.x, y - rhs.y);
    }

    // 곱셈 연산자 (스칼라 곱)
    Vector2 operator*(int scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    // 나눗셈 연산자 (스칼라 나눗셈)
    Vector2 operator/(int scalar) const {
        return Vector2(x / scalar, y / scalar);
    }

    // 비교 연산자 오버로딩
    // 같음 연산자
    bool operator==(const Vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    // 다름 연산자
    bool operator!=(const Vector2& rhs) const {
        return !(*this == rhs);
    }

    // 출력 연산자 오버로딩 (디버깅용)
    friend std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    // 생성자와 연산자 테스트
    Vector2 v1(1, 2);    // 매개변수 생성자
    Vector2 v2 = v1;     // 복사 생성자
    Vector2 v3;          // 기본 생성자
    v3 = std::move(v1);  // 이동 대입 연산자

    // 사칙연산 테스트
    Vector2 v4 = v2 + v3;
    Vector2 v5 = v2 - v3;
    Vector2 v6 = v2 * 2;
    Vector2 v7 = v2 / 2;

    // 비교 연산 테스트
    bool isEqual = (v2 == v3);
    bool isNotEqual = (v2 != v3);

    // 출력
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4 (v2 + v3): " << v4 << std::endl;
    std::cout << "v5 (v2 - v3): " << v5 << std::endl;
    std::cout << "v6 (v2 * 2): " << v6 << std::endl;
    std::cout << "v7 (v2 / 2): " << v7 << std::endl;
    std::cout << "v2 == v3: " << std::boolalpha << isEqual << std::endl;
    std::cout << "v2 != v3: " << std::boolalpha << isNotEqual << std::endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

constexpr int gcd(const int a, const int b) 
{
    return b == 0 ? a : gcd(b, a%b);
}

constexpr int lcm(int a, int b) 
{
    return (a * b) / gcd(a, b);
}

vector<int> minFactors(const int n)
{
    vector<int>
}

int main() {
    int num1 = 48;
    int num2 = 18;

    cout << gcd(num1, num2) << endl;
    cout << lcm(num1, num2) << endl;
    return 0;
}

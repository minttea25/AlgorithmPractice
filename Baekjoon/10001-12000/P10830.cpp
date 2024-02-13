// 행렬 제곱
// https://www.acmicpc.net/problem/10830

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using uint = unsigned int;
using ull = unsigned long long;
using matrix = vector<vector<uint>>;
using vector_ = vector<uint>;

constexpr uint MOD = 1000;

// A^n = A^(n-1) * A (if n is odd)
// A^n = A^(n/2) * A^(n/2) (if n is even)

matrix matrix_multifly(const matrix& a, const matrix& b)
{
    const int N = a.size();

    matrix ret(N, vector_(N));

    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            for (int k=0; k<N; ++k)
            {
                ret[i][j] += (a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return ret;
}

matrix matrix_power(const matrix& a, const ull n)
{
    if (n == 1ull) return a;

    matrix half = matrix_power(a, n/2);
    matrix ret = matrix_multifly(half, half);

    if ((n&1ull) != 0) ret = matrix_multifly(ret, a);

    return ret;
}

void matrix_scalar_mod(matrix& a, const uint mod)
{
    for (int i=0; i<a.size(); ++i)
    {
        for (int j=0; j<a[i].size(); ++j)
        {
            a[i][j] %= mod;
        }
    }
}

void print_matrix(const matrix& a)
{
    for (int i=0; i<a.size(); ++i)
    {
        for (int j=0; j<a[i].size(); ++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    ull b;

    cin >> n >> b;

    matrix a(n, vector_(n));
    for(int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            int input;
            cin >> input;

            a[i][j] = input;
        }
    }

    // b is at least 1
    auto ret = matrix_power(a, b);
    matrix_scalar_mod(ret, MOD);

    print_matrix(ret);

    return 0;
}
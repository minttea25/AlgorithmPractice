// 피보나치 수 6
// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ull = unsigned long long;
using matrix = vector<vector<ull>>;

// [[F_n][F_n-1]] = [[1, 1] [1, 0]]^(n-1) * [[F_1], [F_0]]

// Set A = [[1, 1] [1, 0]]
// A^n = A^(n-1) * A (if n is odd)
// A^n = A^(n/2) * A^(n/2) (if n is even)

constexpr ull MOD = 1'000'000'007ull;
constexpr int FIXED_ROW = 2;
constexpr int FIXED_COLUMN = 2;

constexpr ull F0 = 0;
constexpr ull F1 = 1;
matrix A1 = 
{
{ 1, 1 },
{ 1, 0 }
};
matrix M1 =
{
    {F0}, {F1}
};

matrix matrix_multify(const matrix& a, const matrix& b)
{
    matrix ret(FIXED_ROW, vector<ull>(FIXED_COLUMN));

    for (int i=0; i<FIXED_ROW; ++i)
    {
        for (int j=0; j<FIXED_COLUMN; ++j)
        {
            for (int k=0; k<FIXED_COLUMN; ++k)
            {
                ret[i][j] += (a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return ret;
}

matrix matrix_power(const matrix& a, const ull n)
{
    if (n == 1) return a;

    auto half = matrix_power(a, n/2);
    auto ret = matrix_multify(half, half);
    if ((n&1ull) != 0)
    {
        ret = matrix_multify(ret, a);
    }

    return ret;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    ull n;
    cin >> n;

    // n은 자연수
    if (n == 1) 
    {
        cout << F1 << endl;
    }
    else
    {
        auto M_n = matrix_power(A1, n-1);
        cout << M_n[0][0] % MOD << endl;
    }
    

    return 0;
}
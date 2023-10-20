// 소수 구하기
// https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>
#include <cmath>
#include <memory.h>

using namespace std;

unsigned char sieve[(1'000'000 + 7) / 8];

inline bool isPrime(const int k)
{
    return sieve[k>>3] & (1 << (k&7));
}

inline void setComposite(const int k)
{
    sieve[k>>3] &= ~(1 << (k&7));
}

void eratosthenes(const int n)
{
    memset(sieve, 0b10101010, sizeof(sieve));
    sieve[0] = 0b11111100; // set 0 and 1 to 0(not prime number)

    int sqrtn = static_cast<int>(sqrt(n));
    for(int i=2; i<=sqrtn; ++i)
    {
        if (isPrime(i))
        {
            for(int j=i*i; j<=n; j+=i)
            {
                setComposite(j);
            }
        }
    }
}

int main() 
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int m, n;

    cin >> m >> n;

    eratosthenes(n);

    for(int i=m; i<=n; ++i)
    {
        if (isPrime(i))
        {
            cout << i << '\n';
        }
    }

    return 0;
}
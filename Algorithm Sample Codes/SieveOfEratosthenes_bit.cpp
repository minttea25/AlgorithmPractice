#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

inline bool isPrime(const int k, const vector<unsigned char>& sieve)
{
    return sieve[k>>3] & (1<<(k&7));
}

inline void setComposite(const int k, vector<unsigned char>& sieve)
{
    sieve[k>>3] &= ~(1<<(k&7));
}

vector<unsigned char> eratosthenes(const int n)
{
    vector<unsigned char> sieve((n+7)/8, 170);
    sieve[0] = 255 - 1 - 2;

    int sqrtn = static_cast<int>(sqrt(n));
    for(int i=2; i<=sqrtn; ++i)
    {
        if (isPrime(i, sieve))
        {
            for(int j=i*i; j<=n; j+=i)
            {
                setComposite(j, sieve);
            }
        }
    }

    return sieve;
}

void print(const int k, const bool isPrime)
{
    if(isPrime > 0)
    {
        cout << k << " is prime number!" << '\n';
    }
    else
    {
        cout << k << " is not prime number!" << '\n';
    }
}

int main() 
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    auto sieve = eratosthenes(1000);

    print(123, isPrime(123, sieve));
    print(718, isPrime(718, sieve));
    print(11, isPrime(11, sieve));
    print(139, isPrime(139, sieve));
    print(111, isPrime(111, sieve));

    return 0;
}
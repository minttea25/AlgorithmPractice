#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

#include <bitset>

using namespace std;

struct sieve 
{
public:
    sieve(const int n_): n(n_) 
    {
        assert(n_ <= MAX_N);
        init();
    }
    bool isPrime(const int k) const
    {
        assert(k <= n);
        return bitset.test(k);
    }
private:
    void setComposite(const int k)
    {
        bitset.set(k, 0); // set not prime number(=0)
    }
    void init()
    {
        bitset.set(); // init all bits 1
        int sqrtn = static_cast<int>(sqrt(n));
        setComposite(0);
        setComposite(1);
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
public:
    static const unsigned long long  MAX_N = 0xFFFF; // max is 65535
private:
    int n;
    bitset<MAX_N+1> bitset;
};

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

    sieve s(1000);

    print(123, s.isPrime(123));
    print(718, s.isPrime(718));
    print(11, s.isPrime(11));
    print(139, s.isPrime(139));
    print(111, s.isPrime(111));

    return 0;
}
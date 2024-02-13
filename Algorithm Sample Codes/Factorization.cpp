#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> factors(const int n)
{
    int t = n;
    vector<int> ret;
    int sqrtn = static_cast<int>(sqrt(n));

    for(int i=2; i<=sqrtn; ++i)
    {
        while(t % i == 0)
        {
            t /= i;
            ret.push_back(i);
        }
    }

    return ret;
}

int main()
{
    const int n = 36;
    const auto f = factors(n);
    for(int i=0; i<f.size(); ++i) cout << f[i] << ' ';
    cout << endl;
}
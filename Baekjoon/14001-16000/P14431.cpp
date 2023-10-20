// 소수 마을
// https://www.acmicpc.net/problem/14431

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

constexpr int MAX = 3000;
//constexpr int MAX_N = static_cast<int>(sqrt(MAX * MAX * 2));
constexpr int MAX_N = 9000;
unsigned char sieve[(MAX_N + 7) / 8];

inline bool isPrime(const int k)
{
    return sieve[k>>3] & (1<<(k&7));
}

void eratosthenes()
{
    memset(sieve, 0b10101010, sizeof(sieve));
    sieve[0] = 0b10101100;

    int sqrtn = static_cast<int>(sqrt(MAX_N));
    for(int i=2; i<=sqrtn; ++i)
    {
        if (isPrime(i))
        {
            for(int j=i*i; j<=MAX_N; j+=i)
            {
                sieve[j>>3] &= ~(1<<(j&7));
            }
        }
    }
}

bool canVisit(const pii a, const pii b, int& dist)
{
    int t = static_cast<int>(hypot(b.first - a.first, b.second - a.second));
    if (isPrime(t))
    {
        dist = t;
        return true;
    }
    else return false;
}

int dijkstra(const vector<pii>& towns, int n)
{
    const int v = towns.size();
    vector<int> dist(v, MAX_N);
    vector<bool> visited(v, false);

    dist[n] = 0;

    for (int i=0; i<v-1; ++i)
    {
        int j = 0;
        int mn = MAX_N;

        // find shortest town of town[i]
        for (int ii=0; ii<v; ++ii)
        {
            if (visited[ii] == false && dist[ii] <= mn)
            {
                mn = dist[ii];
                j = ii;
            }
        }

        visited[j] = true;

        for (int ii=0; ii<v; ++ii)
        {
            int d = MAX_N;

            if (canVisit(towns[j], towns[ii], d) == true && visited[ii] == false)
            {
                dist[ii] = min(dist[ii], dist[j] + d);
            }
        }
    }

    return dist[1] == MAX_N ? -1 : dist[1];
}

int main() 
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    eratosthenes();

    int x1, x2, y1, y2;
    vector<pii> towns;
    cin >> x1 >> y1 >> x2 >> y2;

    towns.push_back({x1, y1});
    towns.push_back({x2, y2});

    int n;
    cin >> n;
    
    for(int i=0; i<n; ++i)
    {
        int x, y;
        cin >> x >> y;
        towns.push_back({x,y});
    }

    cout << dijkstra(towns, 0) << endl;

    return 0;
}
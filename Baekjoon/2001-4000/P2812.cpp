// 크게 만들기
// https://www.acmicpc.net/problem/2812

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

// It includes almost all header files for algorithm practice.
// It is not a standard library header for C++, but a valid header only with the gcc compiler.
// #include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

deque<int> d;
int N, K;
int n[500001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    string s;
    cin >> s;
    FOR(i, 0, N)
    {
        n[i] = s[i] - '0';
    }

    d.push_back(n[0]);
    int i = 1;
    for (; i <N; i++)
    {
        if (K == 0)
        {
            break;
        }

        while (true)
        {
            if (d.empty() == true || K == 0)
            {
                d.push_back(n[i]);
                break;
            }

            if (d.back() < n[i])
            {
                d.pop_back();
                K--;
            }
            else
            {
                d.push_back(n[i]);
                break;
            }
        }
    }

    // 만약 pop해야 되는 숫자가 남아있을 경우 뒤에서 없애기
    if (K != 0) {
        FOR(j, 0, K) {
            d.pop_back();
        }
    }

    // print ans stack + n[i~]
    deque<int>::iterator it;
    for (it = d.begin(); it != d.end(); it++)
    {
        cout << *it;
    }
    for (; i < N; i++)
    {
        cout << n[i];
    }
    cout << endl;


    return 0;
}
// N과 M (2)
// https://www.acmicpc.net/problem/15650

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void _print_permutation(int nth, const int n, const int m, vector<int>& arr);

void print_permutation(const int n, const int m)
{
    vector<int> v;
    _print_permutation(0, n, m, v);
}

void _print_permutation(int nth, const int n, const int m, vector<int>& arr)
{
    if (arr.size() == m)
    {
        // print
        for (auto a : arr)
        {
            cout << a << ' ';
        }
        cout << endl;
        return;
    }
    

    for (int i=nth; i<n; ++i)
    {
        arr.push_back(i+1);
        _print_permutation(i+1, n, m, arr);
        arr.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m;

    cin >> n >> m;

    print_permutation(n, m);

    return 0;
}
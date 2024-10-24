// N과 M (12)
// https://www.acmicpc.net/problem/15666

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void _print_combination(int nth, const int m, const vector<int>& numbers, vector<int>& arr);

void print_combination(const int m, const vector<int>& numbers)
{
    vector<int> v;
    _print_combination(0, m, numbers, v);
}

void _print_combination(int nth, const int m, const vector<int>& numbers, vector<int>& arr)
{
    const int n = numbers.size();

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
        arr.push_back(numbers[i]);
        _print_combination(i, m, numbers, arr);
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

    vector<int> set(n);
    for (int i=0; i<n; ++i)
    {
        int input;
        cin >> input;
        set[i] = input;
    }

    sort(set.begin(), set.end());
    set.erase(unique(set.begin(), set.end()), set.end());

    print_combination(m, set);

    return 0;
}
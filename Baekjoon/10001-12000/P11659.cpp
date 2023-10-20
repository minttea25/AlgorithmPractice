// 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> cumSum;

    int input;
    cumSum.push_back(0);
    for(int i=1; i<=n; ++i)
    {
        cin >> input;
        cumSum.push_back(cumSum[i-1] + input);
    }


    int begin;
    int end;
    while(m>0)
    {
        m--;

        cin >> begin >> end;

        cout << cumSum[end] - cumSum[begin-1] << '\n';
    }

    return 0;
}
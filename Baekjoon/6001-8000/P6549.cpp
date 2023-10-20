// 히스토그램에서 가장 큰 직사각형
// https://www.acmicpc.net/problem/6549

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int n;
    int input;

    pair<int, int> stack[100001];
    // set base
    stack[0] = {0, 0};
    int pos = 1;

    unsigned long long ret = 0;
    while (true)
    {
        cin >> n;

        if (n == 0) break;

        // push base
        stack[0] = {0, -1};
        pos = 1;
        ret = 0;

        for(int i=1; i<=n+1; ++i)
        {
            if (i == n+1) input = 0;
            else cin >> input; // get height of ith sq

            if (input == stack[pos-1].second)
            {
                // remove previous one
                // s[i] contains the s[i-1].
                pos--;
            }
            else
            {
                while (pos > 1 && input < stack[pos-1].second)
                {
                    // determined right[i-1] => calc s[i-1] = (right[i-1] - left[i-1] - 1) * height[i-1]
                    auto top = stack[pos-1];

                    int right = i;
                    int left = stack[pos-1-1].first;
                    ret = max(ret, (right - left - 1) * static_cast<unsigned long long>(top.second));
                    pos--; // remove calculated i-1
                }
            }

            // push
            stack[pos] = {i, input};
            pos++;
        }

        cout << ret << endl;
    }

    return 0;
}
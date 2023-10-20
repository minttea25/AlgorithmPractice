// 색종이 만들기
// https://www.acmicpc.net/problem/2630

#include <iostream>
#include <vector>

using namespace std;

struct Colors
{
public:
    int white = 0;
    int blue = 0;
};

void cut(const int n, const pair<int, int> pos, const vector<vector<bool>>& papers, Colors& ans)
{
    // 전체가 같은 색인지 확인
    const bool color = papers[pos.first][pos.second];
    bool same = true;
    for(int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (color != papers[pos.first+i][pos.second+j])
            {
                same = false;
                break;
            }
        }
        if (same == false) break;
    }

    if (same == true)
    {
        if (color == 0) ans.white++;
        else ans.blue++;
        return;
    }

    cut(n/2, pos, papers, ans);
    cut(n/2, {pos.first+n/2, pos.second}, papers, ans);
    cut(n/2, {pos.first, pos.second+n/2}, papers, ans);
    cut(n/2, {pos.first+n/2, pos.second+n/2}, papers, ans);
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n; // n = 2^k, k:[1, 7]
    cin >> n;

    vector<vector<bool>> papers(n, vector<bool>(n, false));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            bool input;
            cin >> input;
            papers[i][j] = input;
        }
    }

    Colors ans;
    cut(n, {0, 0}, papers, ans);

    cout << ans.white << '\n' << ans.blue << '\n';

    return 0;
}
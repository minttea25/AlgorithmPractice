// 회의실 배정
// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

bool comp(const pii& a, const pii& b)
{
    if (a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<pii> meetings;

    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        int s, e;
        cin >> s >> e;
        meetings.push_back({s, e});
    }

    sort(meetings.begin(), meetings.end(), comp); // 끝난 시간으로 정렬

    int time = 0;
    int count = 0;
    for(int i=0; i<n; ++i)
    {
        const int start = meetings[i].first;
        const int end = meetings[i].second;
        if (time <= start)
        {
            time = end;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
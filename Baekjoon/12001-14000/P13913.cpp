// 숨박꼭질 4
// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'
using namespace std;

constexpr int MAX = 150000;
constexpr short NONE = 0x00;
constexpr short WAY1 = 0x01; // x + 1
constexpr short WAY2 = 0x10; // x - 1
constexpr short WAY3 = 0x11; // teleport
constexpr short START = 0xFF;

constexpr int MOVE1(const int pos) { return pos+1; }
constexpr int MOVE2(const int pos) { return pos-1; }
constexpr int TELEPORT(const int pos) { return pos * 2; }

vector<int> back_tracking(const vector<short>& track, const int des);

vector<int> solve(const int start, const int des)
{
    vector<short> track(MAX, NONE);
    queue<int> q;

    if (start == des) return {start};

    q.push(start);
    track[start] = START;

    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();

        int p1 = MOVE1(p);
        if (p1 < MAX && track[p1] == NONE)
        {
            track[p1] = WAY1;
            if (p1 == des) return back_tracking(track, p1);
            q.push(p1);
        }

        int p2 = MOVE2(p);
        if (p2 >= 0 && track[p2] == NONE)
        {
            track[p2] = WAY2;
            if (p2 == des) return back_tracking(track, p2);
            q.push(p2);
        }

        int p3 = TELEPORT(p);
        if (p3 < MAX && track[p3] == NONE)
        {
            track[p3] = WAY3;
            if (p3 == des) return back_tracking(track, p3);
            q.push(p3);
        }
    }

    return {}; // unreachable
}

vector<int> back_tracking(const vector<short>& track, const int des)
{
    vector<int> v;
    short way = track[des];
    int pos = des;
    v.push_back(des);
    while (way != START)
    {
        // way1 => x - 1
        // way2 => x + 1
        // way3 => x / 2
        switch (way)
        {
        case WAY1:
            pos = pos - 1;
            break;
        case WAY2:
            pos = pos + 1;
            break;
        case WAY3:
            pos = pos / 2;
            break;
        default:
            // unreachable
            break;
        }

        v.push_back(pos);
        way = track[pos];
    }

    return v;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    auto ans = solve(n, k);

    cout << ans.size() - 1 << endl;
    // print (reverse)
    for (auto it = ans.end() - 1; it >= ans.begin(); it--)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}

// 확인 필요! (일단 예제는 맞음...)

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

constexpr int INF = 99999;
constexpr int MAX = 12;
constexpr int MAX_SEM = 10;

constexpr void listen(uint& set, const int k) { set |= (1 << k); }
constexpr bool listenable(const uint set, const uint preSubject) { return (set & preSubject) == preSubject; }
constexpr bool contains(const uint set, const int k) { return set & (1 << k); }
constexpr void remove(uint& set, const int k) { set &= (~(1 << k)); }
constexpr uint diff(const uint set1, const uint set2) { return set1 & ~set2; }

uint cache[1 << MAX][MAX_SEM];

void print(uint set)
{
    int b = sizeof(set) * 8;
    for(int i = b - 1; i>=0; --i)
    {
        cout << ((set >> i) & 1);
        if (i % 4 == 0 && i != 0) cout << '|';
        else cout << ' ';
    }
    cout << endl;
}

uint solve(const int semester, uint& taken, const vector<uint>& lectures, const vector<uint>& preSubjects, const int subject_n, const int max_listenable, const int need)
{
    if (semester == lectures.size()) return INF;

    uint& ret = cache[taken][semester];
    if (ret != 0) return ret;

    //uint canTake = lectures[semester] & (~taken); // 이번학기에 들을 수 있는 과목 (이미 들었던 과목 제외)
    uint canTake = diff(lectures[semester], taken);
    ret = INF;
    // left only listenable lectures in now(set)
    for(int i=0; i<subject_n; ++i) 
    {
        if (contains(lectures[semester], i) && listenable(taken, preSubjects[i]) == false) remove(canTake, i);
    }

    cout << semester << " - " << taken << ": ";
    print(canTake);

    for(uint subset = canTake; subset > 0; subset = ((subset - 1) & canTake))
    {
        if (__builtin_popcount(subset) <= max_listenable)
        {
            uint t = subset | taken;
            if (__builtin_popcount(t) == need) ret = min(ret, 1u);
            else ret = min(ret, solve(semester+1, t, lectures, preSubjects, subject_n, max_listenable, need) + 1);
        }
    }

    // 아무것도 안들었을 경우
    ret = min(ret, solve(semester+1, taken, lectures, preSubjects, subject_n, max_listenable, need));

    return ret;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int tc;
    cin >> tc; 

    int n, k, l, m;
    vector<uint> lectures;
    vector<uint> preSubjects;
    for(int i=0; i<tc; ++i)
    {
        for(int a=0; a<(1 << MAX); ++a)
        {
            for (int b =0; b<MAX_SEM; ++b) cache[a][b] = 0;
        }

        lectures.clear();
        preSubjects.clear();

        cin >> n >> k >> m >> l;
        
        for(int j=0; j<n; ++j)
        {
            int t;
            cin >> t;

            uint set = 0;
            for (int ii=0; ii<t; ++ii)
            {
                uint pre;
                cin >> pre;
                listen(set, pre);
            }
            preSubjects.push_back(set);
        }

        for(int j=0; j<m; ++j)
        {
            int t;
            cin >> t;

            uint set = 0;
            for (int ii=0; ii<t; ++ii)
            {
                uint subject;
                cin >> subject;
                listen(set, subject);
            }
            lectures.push_back(set);
        }

        uint set = 0;
        uint ans = solve(0, set, lectures, preSubjects, n, l, k);
        if (ans == INF) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}
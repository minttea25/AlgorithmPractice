// 가르침
// https://www.acmicpc.net/problem/1062

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

constexpr void add(uint& set, const int k) { set |= (1 << k); }
constexpr uint union_set(const uint& set1, const uint& set2) { return set1 | set2; }
constexpr uint diff(const uint set1, const uint set2) { return set1 & ~set2; }

constexpr uint base_set = (1 << 0) + (1 << 2) + (1 << 8) + (1 << 13) + (1 << 19);
constexpr int base_set_count = 5;

inline uint getWordSet(const string& s)
{
    uint set = 0;
    for(int i=0; i<s.size(); ++i)
    {
        const int k = static_cast<int>((s[i] - 'a'));
        add(set, k);
    }
    return diff(set, base_set);
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    vector<uint> wordSet;
    int n, k;

    cin >> n >> k;
    for(int i=0; i<n; ++i)
    {
        string s;
        cin >> s;
        wordSet.push_back(getWordSet(s));
    }

    int ans = 0;
    const int cnt = k - base_set_count;
    if (cnt < 0) ans = 0;
    else if (cnt == 0)
    {
        // subset이 empty 일 경우
        for(int i=0; i<wordSet.size(); ++i) if (wordSet[i] == 0) ans++;
    }
    else
    {
        uint m_set = 0;
        for(int i=0; i<wordSet.size(); ++i)
        {
            if (__builtin_popcount(wordSet[i]) <= cnt) m_set = union_set(m_set, wordSet[i]);
        }

        for(uint subset = m_set; subset>0; subset = ((subset-1) & m_set))
        {
            if (__builtin_popcount(subset) > cnt) continue;

            int t = 0;
            for(int i=0; i<wordSet.size(); ++i)
            {
                if (diff(wordSet[i], subset) == 0) t++;
            }
            ans = max(t, ans);
        }
        // subset이 empty일 경우 위에서 처리
    }

    cout << ans << '\n';

    return 0;
}
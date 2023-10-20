// 집합
// https://www.acmicpc.net/problem/11723

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

constexpr int ADD = 1;
constexpr int REMOVE = 2;
constexpr int CHECK = 3;
constexpr int TOGGLE = 4;
constexpr int ALL = 5;
constexpr int EMPTY = 6;

struct bitset_32
{
public:
    bitset_32(const bool full = false) : n(MAX)
    {
        if (full == true) reset1();
        else reset0();
    }
    bitset_32(const unsigned int set_) :_set(set_) {}
    unsigned int getSet() const
    {
        return _set;
    }
    void reset0()
    {
        _set = 0;
    }
    void reset1()
    {
        _set = (1ull << n) - 1ull;
    }
    void add(const unsigned int k) 
    {
        _set |= (1<<k);
    }
    bool contains(const unsigned int k) const
    {
        return _set&(1 << k);
    }
    void remove(const unsigned int k)
    {
        _set &= ~(1 << k);
    }
    void toggle(const unsigned int k)
    {
        _set ^= (1 << k);
    }
public:
    static const unsigned int MAX = 32;
private:
    int n;
    unsigned int _set;
};

int op_(const string& s)
{
    if (s.compare("add") == 0) return ADD;
    else if (s.compare("remove") == 0) return REMOVE;
    else if (s.compare("check") == 0) return CHECK;
    else if (s.compare("toggle") == 0) return TOGGLE;
    else if (s.compare("all") == 0) return ALL;
    else if (s.compare("empty") == 0) return EMPTY;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;

    bitset_32 set;
    set.reset0();

    string op;
    unsigned int v;
    while(m > 0)
    {
        --m;
        
        cin >> op;

        switch (op_(op))
        {
        case CHECK:
            cin >> v;
            cout << set.contains(v-1) << '\n';
            break;
        case ADD:
            cin >> v;
            set.add(v-1);
            break;
        case REMOVE:
            cin >> v;
            set.remove(v-1);
            break;
        case TOGGLE:
            cin >> v;
            set.toggle(v-1);
            break;
        case ALL:
            set.reset1();
            break;
        case EMPTY:
            set.reset0();
            break;
        }
    }

    return 0;
}
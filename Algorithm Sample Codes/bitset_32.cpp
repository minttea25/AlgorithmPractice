#include <iostream>
#include <assert.h>

using namespace std;

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
    void intersection(const bitset_32& set)
    {
        _set &= set.getSet();
    }
    void union_(const bitset_32& set)
    {
        _set |= set.getSet();
    }
    bitset_32 getToggledSet(const bitset_32& set) const
    {
        return bitset_32(_set ^ set.getSet());
    }
    friend bitset_32 difference(const bitset_32& set1, const bitset_32& set2)
    {
        return bitset_32(set1.getSet() & (~(set2.getSet())));
    }
    friend bitset_32 union_(const bitset_32& set1, const bitset_32& set2)
    {
        return bitset_32(set1.getSet() | set2.getSet());
    }
    friend bitset_32 toggled(const bitset_32& set1, const bitset_32& set2)
    {
        return bitset_32(set1.getSet() ^ set2.getSet());
    }
    friend bitset_32 intersection(const bitset_32& set1, const bitset_32& set2)
    {
        return bitset_32(set1.getSet() & set2.getSet());
    }

    bitset_32 operator-(const bitset_32& rhs) const
    {
        return bitset_32(_set & (~(rhs.getSet())));
    }
    bitset_32 operator+(const bitset_32& rhs) const
    {
        return bitset_32(_set | rhs.getSet());
    }

    friend ostream& operator<<(ostream& os, const bitset_32& rhs)
    {
        const unsigned int n = rhs.getSet();
        int b = sizeof(n) * 8;
        for(int i = b - 1; i>=0; --i)
        {
            os << ((n >> i) & 1);
            if (i % 4 == 0 && i != 0) os << '|';
            else os << ' ';
        }

        return os;
    }
public:
    static const unsigned int MAX = 32;
private:
    int n;
    unsigned int _set;
};

int main()
{
    cout.setf(ios_base::boolalpha);

    bitset_32 set(false);

    cout <<  "set: " << set << endl;

    set.add(20);
    cout <<  "after add 20: " << set << endl;

    set.union_(bitset_32((unsigned int)5));
    cout <<  "after union with 5: " << set << endl;

    set.remove(20);
    cout <<  "after remove 20: " << set << endl;

    cout << "contains 0 ?: " << set.contains(0) << endl;
    cout << "contains 1 ?: " << set.contains(1) << endl;

    set.toggle(0);
    cout << "after toggle 0: " << set << endl;

    set.toggle(10);
    cout << "after toggle 10: " << set << endl;

    bitset_32 set1024 = bitset_32((unsigned int)1024);
    cout << "set(1024): " << set1024 << endl;
    cout << "set - set(1024): " << (set - set1024) << endl;

    bitset_32 set20 = bitset_32((unsigned int)(4 + 16));
    cout << "set20: " << set20 << endl;
    cout << "intersection of set and set20: " << intersection(set, set20) << endl;
    cout << "toggled of set and set20: " << toggled(set, set20) << endl;

    return 0;
}
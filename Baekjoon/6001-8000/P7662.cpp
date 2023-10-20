// 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662

#include <iostream>
#include <set>

using namespace std;

constexpr char INSERT = 'I';
constexpr char DELETE = 'D';
constexpr int D_MAX = 1;
constexpr int D_MIN = -1;

void doOperation(const char opType, const int opValue, multiset<int>& s)
{
    if (s.size() == 0 && opType == DELETE) return;

    if (opType == DELETE)
    {
        if (opValue == D_MIN) s.erase(s.begin());
        else s.erase(--s.end());
    }
    else
    {
        s.insert(opValue);
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;

    while(t > 0)
    {
        t--;

        int k;
        cin >> k;

        cin.ignore(100000, '\n');
        
        string op;
        multiset<int> s;
        for(int i=0; i<k; ++i)
        {
            getline(cin, op);
            const char opType = op[0];
            const int opValue = stoi(op.substr(2));

            doOperation(opType, opValue, s);
        }

        if (s.empty() == true) cout << "EMPTY" << '\n';
        else cout << *(--s.end())<< ' ' << *s.begin() << '\n';
    }

    return 0;
}
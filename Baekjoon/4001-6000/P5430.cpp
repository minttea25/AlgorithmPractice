// AC
// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

class AC
{
public:
    AC(deque<int>& arr) : _arr(arr) {}
    bool operate(const string& operation)
    {
        for(const char& o : operation)
        {
            if (o == REVERSE) _reverse = !_reverse;
            else
            {
                if (_arr.size() == 0) return false;
                
                if (_reverse == false) _arr.pop_front();
                else _arr.pop_back();
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& os, const AC& ac)
    {
        os << '[';
        const int size = ac._arr.size();
        for(int i=0; i<size; ++i)
        {
            const int t = ac._reverse ? ac._arr[size-i-1] : ac._arr[i];
            os << t;
            if (i < size-1) os << ',';
        }
        os << ']';

        return os;
    }
public:
    const char REVERSE = 'R';
    const char DISCRAD = 'D';
private:
    deque<int> _arr;
    bool _reverse = false;
};

deque<int> splitToDeque(const string& s, char delim = ',')
{
    deque<int> dq;
    if (s.size() == 0) return dq;

    // split
    string token;
    std::istringstream tokenStream(s);
    while(getline(tokenStream, token, delim))
    {
        dq.push_back(std::stoi(token));
    }

    return dq;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int tc;
    cin >> tc;

    for(int i=0; i<tc; ++i)
    {
        string operation;
        int len;
        string arr;
        cin >> operation >> len >> arr;

        // cout << operation << ' ' << len << ' ' << arr << endl;
        arr = arr.substr(1, arr.size()-2);
        auto dq = splitToDeque(arr);
        AC ac(dq);

        bool suc = ac.operate(operation);
        if (suc == true) cout << ac << '\n';
        else cout << "error" << '\n';
    }

    return 0;
}
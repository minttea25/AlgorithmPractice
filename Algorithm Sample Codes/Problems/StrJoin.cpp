// p.380 문자열 합치기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& v) {
    int ret = 0;
    priority_queue<int> q;

    for(int i=0; i<v.size(); ++i) q.push(-v[i]);

    while(q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        int c = (a + b) * -1;

        ret += c;
        q.push(-c);
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<int> v;
    int t;
    cin >> t;

    for(int i=0; i<t; ++i) {
        v.clear();

        int l;
        cin >> l;
        
        for(int j=0; j<l; ++j) {
            int in;
            cin >> in;
            v.push_back(in);
        }

        cout << solve(v) << endl;
    }
}
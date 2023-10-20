// 교환
// https://www.acmicpc.net/problem/1039

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

using namespace std;

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

string N;
int K;
iv nv;
iv mxv;
int mx;
int s;
bool visited[1000001] = {false, };

int sum(iv& v) {
    int sum = 0;
    for(int i=0, idx = v.size()-1; idx >= 0; i++, idx--) {
        sum += (v[idx] * (int)(pow(10, i)));
    }
    return sum;
}

iip BFS(string start) {
    queue<string> q;
    int count = 0;
    int x = -1;

    q.push(start);
    q.push("0");

    while(q.empty() == false) {
        string pp = q.front();
        q.pop();

        if (pp.compare("0") == 0) {
            count++;
            if (count == K) return{count, x};
            q.push("0");
            continue;
        }

        for(int i=0; i<s-1; i++) {
            for(int j=i+1; j<s; j++) {
                if(i==0 && (pp[j] - '0') == 0) continue;

                string p = pp; // deep copy

                swap(p[i], p[j]);
                int t = stoi(p);

                if (visited[t] == true) {
                    continue;
                }

                x = max(t, x);
                if (x == mx) {
                    return {count+1, x};
                }

                q.push(p);
                visited[t] = true;
            }
        }
    }

    return {-1, -1};
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    for(auto v : N) {
        nv.push_back(v - '0');
        mxv.push_back(v - '0');
    }
    s = nv.size();
    sort(begin(mxv), end(mxv), greater<int>());
    mx = sum(mxv);

    iip p = BFS(N);

    if (p.first == -1) {
        cout << -1 << endl;
    }
    else if (p.first <= K) {
        // found max value
        string t = to_string(p.second);
        for(int i=0; i<t.size()-1; i++) {
            if (t[i] == t[i+1]) {
                cout << p.second << endl;
                return 0;
            }
        }

        if ((K - p.first) % 2 == 0) {
            cout << p.second << endl;
        }
        else {
            swap(t[t.size()-1], t[t.size()-2]);
            cout << t << endl;
        }
    }
    else {
        cout << p.second << endl;
    }

    return 0;
}
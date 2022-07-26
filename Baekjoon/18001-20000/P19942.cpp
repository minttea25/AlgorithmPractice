// 다이어트
// https://www.acmicpc.net/problem/19942

#include <iostream>
#include <vector>
#include <algorithm>

// It includes almost all header files for algorithm practice.
// It is not a standard library header for C++, but a valid header only with the gcc compiler.
// #include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LOG(x) cout<<#x<<": "<<x<<endl
#define FOR(i, s, e) for(int i=s; i<e; ++i)
#define FOR_(i, s, e) for (int i=s; i<=e; ++i)
#define iFOR(i, s, e) for(int i=s; i>e; --i)
#define iFOR_(i, s, e) for (int i=s; i>=e; --i)

typedef long long ll;
typedef vector<int, int> iiv;
typedef vector<int> iv;
typedef pair<int, int> iip;

#define MAX 15+1

class Food {
    public :
    int p, f, s, v, c;
};

int N; // number of food ingredients
// nutreints of protein, fat, carbohydrate, vitamin
int mp, mf, ms, mv;
int minCost = 10000000;

Food foods[MAX];
int ansSet[MAX] = {0, };
bool visited[MAX]; // for back-tracking


void tracking(int food, int p, int f, int s, int v, int cost) {
    if (p>=mp && f>=mf && s>=ms && v>=mv) {
        if (cost < minCost) {
            // clear ansSet to 0
            for (int i=0; i<N; i++) {
                ansSet[i] = 0;
            }
            int idx = 0;
            for (int i=1; i<=N; i++) {
                if (visited[i]) {
                    ansSet[idx++] = i;
                }
            }
            minCost = cost;
            //log(minCost);
        }
        return;
    }

    for (int i=food; i<=N; i++) {
        if (!visited[i]) {
            visited[i] = true;

            p += foods[i].p;
            f += foods[i].f;
            s += foods[i].s;
            v += foods[i].v;
            cost += foods[i].c;

            tracking(i, p, f, s, v, cost);

            visited[i] = false;

            p -= foods[i].p;
            f -= foods[i].f;
            s -= foods[i].s;
            v -= foods[i].v;
            cost -= foods[i].c;
        }
        
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int tp, tf, ts, tv, tc;

    cin >> N >> mp >> mf >> ms >> mv;

    for (int i=1; i<=N; i++) {
        cin >> tp >> tf >> ts >> tv >> tc;

        foods[i] = {tp, tf, ts, tv, tc};
    }

    tracking(1, 0, 0, 0, 0, 0);

    if (ansSet[0] == 0) {
        cout << -1 << endl;
    }
    else {
        cout << minCost << endl;
        for (int e : ansSet) {
            if (e) {
                cout << e << ' ';
            }
        }
        cout << endl;
    }
    
    return 0;
}
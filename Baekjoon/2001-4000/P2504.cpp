// 괄호의 값
// https://www.acmicpc.net/problem/2504


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// It includes almost all header files for algorithm practice.
// It is not standard library header of C++, and used on only gcc compiler.
// #include <bits/stdc++.h>

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

constexpr char Open1 = '('; // = 40
constexpr char Close1 = ')'; // = 41
constexpr char Open2 = '['; // 92
constexpr char Close2 = ']'; // 93

stack<char> stk;
string input;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    cin >> input;

    int part = 0;
    int tmp = 1;
    int ans = 0;

    FOR(i, 0, input.length()) {
        char c = input[i];

        if (c == Open1 || c == Open2) {
            stk.push(c);
            tmp *= (c==Open1 ? 2 : 3);
        }
        else {
            if (stk.empty()) {
                ans = 0;
                break;
            }

            if (c == Close1) {
                if (stk.top() != Open1) {
                    ans = 0;
                    break;
                }

                if (i>0 && input[i-1] == Open1) {
                    part += tmp;
                }
                tmp /= 2;
            }
            else if (c == Close2) {
                if (stk.top() != Open2) {
                    ans = 0;
                    break;
                }

                if (i>0 && input[i-1] == Open2) {
                    part += tmp;
                }
                tmp /= 3;
            }
            stk.pop();
        }

        if (stk.empty()) {
            ans += part;
            part = 0;
            tmp = 1;
        }
    }

    cout << ans << endl;

    return 0;
}
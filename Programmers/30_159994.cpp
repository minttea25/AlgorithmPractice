// 카드 뭉치
// https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    bool flag = true;
    int a = 0, b = 0;
    for(int i=0; i<goal.size(); i++) {
        if (cards1[a] == goal[i]) {
            a++;
            continue;
        }
        else if (cards2[b] == goal[i]) {
            b++;
            continue;
        }
        else {
            flag = false;
            break;
        }
    }
    
    return flag ? "Yes" : "No";
}
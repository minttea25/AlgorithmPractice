// 문자열 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/140108

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    char x;
    int xCount = 0;
    int eCount = 0;

    for(int i=0; i<s.size(); i++) {
        if (xCount == 0) {
            x = s[i];
            xCount++;
        }
        else if (s[i] == x) xCount++;
        else {
            eCount++;
            if (xCount == eCount) {
                answer++;
                xCount = eCount = 0;
            }
        }
    }

    if (!(xCount == 0 && eCount == 0)) {
        answer++;
    }

    return answer;
}
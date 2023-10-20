// 바탕화면 정리
// https://school.programmers.co.kr/learn/courses/30/lessons/161990

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    answer.resize(4);
    answer[0] = 51;
    answer[1] = 51;
    answer[2] = 0;
    answer[3] = 0;
    
    for (int i=0; i<wallpaper.size(); ++i) {
        for(int j=0; j<wallpaper[i].size(); ++j) {
            if (wallpaper[i][j] == '#') {
                answer[1] = min(answer[1], j);
                answer[3] = max(answer[3], j);
                answer[0] = min(answer[0], i);
                answer[2] = max(answer[2], i);
            }
        }
    }
    
    answer[2] += 1;
    answer[3] += 1;
    
    return answer;
}
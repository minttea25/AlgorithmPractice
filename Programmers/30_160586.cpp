// 대충 만든 자판
// https://school.programmers.co.kr/learn/courses/30/lessons/160586

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr char A = 'A';

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int map[100];
    
    fill(map, map + 100, 100001);
    
    for(auto keys : keymap) {
        for(int i=0; i<keys.size(); i++) {
            map[keys[i] - A] = min(map[keys[i]-A], i+1);
        }
    }


    for(auto target : targets) {
        int cnt = 0;
        for(int i=0; i<target.size(); i++) {
            cnt += map[target[i] - A];
        }
        if (cnt >= 100001) answer.push_back(-1);
        else answer.push_back(cnt);
    }
    
    return answer;
}
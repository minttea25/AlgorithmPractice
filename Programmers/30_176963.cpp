// 추억 점수
// https://school.programmers.co.kr/learn/courses/30/lessons/176963

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    unordered_map<string, int> dict;
    for(int i=0; i<name.size(); ++i) {
        dict.insert({name[i], yearning[i]});
    }

    for(auto a_photo : photo) {
        int score = 0;
        for(auto p : a_photo) {
            auto t = dict.find(p);
            if (t != dict.end()) {
                score += t->second;
            }
        }
        answer.push_back(score);
    }

    return answer;
}
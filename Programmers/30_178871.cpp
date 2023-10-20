// 달리기 경주
// https://school.programmers.co.kr/learn/courses/30/lessons/178871

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> dict;
    int i=0;
    for(auto& p : players) {
        answer.push_back(p);
        dict.insert({p, i});
        i++;
    }

    for(auto&p : callings) {
        swap(answer[dict[p]], answer[dict[p] - 1]);
        int t = dict[p];
        dict[p] -= 1;
        dict[answer[t]] += 1;
    }

    return answer;
}
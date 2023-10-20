// 호텔 대실
// https://school.programmers.co.kr/learn/courses/30/lessons/155651

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int ZERO = '0';

int getTime(string time) {
    return 60*((time[0] - ZERO)*10 + time[1] - ZERO) + 10 * (time[3] - ZERO) + (time[4] - ZERO);
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> books;
    for(auto t : book_time) {
        books.push_back({getTime(t[0]), getTime(t[1])});
    }
    sort(books.begin(), books.end());
    
    vector<int> schedule;
    for(int i=0; i < books.size(); i++) {
        bool flag = false;
        for(auto& time : schedule) {
            if (time <= books[i].first) {
                time = books[i].second + 10;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            schedule.push_back(books[i].second + 10);
        }
    }
    return schedule.size();
}
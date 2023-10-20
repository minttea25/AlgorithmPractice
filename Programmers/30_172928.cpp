// 공원 산책
// https://school.programmers.co.kr/learn/courses/30/lessons/172928

#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

constexpr char NORTH = 'N';
constexpr char SOUTH = 'S';
constexpr char WEST = 'W';
constexpr char EAST = 'E';
constexpr char ZERO = '0';
constexpr char X = 'X';
constexpr char START = 'S';

const pii DIR_NORTH = {-1, 0};
const pii DIR_SOUTH = {1, 0};
const pii DIR_WEST = {0, -1};
const pii DIR_EAST = {0, 1};
const pii DUMMY = {0, 0};

pii getDirection(char dir) {
    switch(dir) {
        case NORTH:
            return DIR_NORTH;
        case SOUTH:
            return DIR_SOUTH;
        case WEST:
            return DIR_WEST;
        case EAST:
            return DIR_EAST;
    }
    return DUMMY;
}

pii move(pii begin, char dir, int dist, const int height, const int width, const vector<string>& park) {
    int h = begin.first;
    int w = begin.second;
    auto d = getDirection(dir);
    
    int th = h + d.first * dist;
    int tw = w + d.second * dist;
    if (th >= height || th < 0) return DUMMY;
    if (tw >= width || tw < 0) return DUMMY;
    
    for(int i=0; i<dist; i++) {
        h += d.first;
        w += d.second;
        if (park[h][w] == X) return DUMMY;
    }
    
    return {d.first * dist, d.second * dist};
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    const int height = park.size();
    const int width = park[0].size();
    int w=0, h=0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if (park[i][j] == START) {
                h = i;
                w = j;
                break;
            }
        }
    }
    
    
    for(auto& s : routes) {
        auto d = move({h, w}, s[0], s[2] - ZERO, height, width, park);
    
        h += d.first;
        w += d.second;
    }
    
    answer.push_back(h);
    answer.push_back(w);
    return answer;
}
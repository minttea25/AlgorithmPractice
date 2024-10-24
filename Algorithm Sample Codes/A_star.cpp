#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

using Pos = pair<int, int>;
using Map = vector<vector<int>>;

struct Node
{
public:
    int x, y;
    double f; // f = g + c // sample
    double g; 
    double h; // heuristic

    bool operator>(const Node& other) const
    {
        return f > other.f;
    }
};

double heuristic(const int x1, const int y1, const int x2, const int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<Pos> aStar(const Pos start, const Pos des, const Map& map)
{
    const int rows = map.size();
    const int cols = map[0].size();

    priority_queue<Node, vector<Node>, greater<Node>> openList;
    vector<vector<bool>> closedList(rows, vector<bool>(cols, false));

    Node start_node = {start.first, start.second, 0, 0, heuristic(start.first, start.second, des.first, des.second)};
    openList.push(start_node);
    
    vector<Pos> path;

    while (openList.empty() == false)
    {
        Node current = openList.top();
        openList.pop();

        int x = current.x;
        int y = current.y;
        if (closedList[x][y] == true) continue;
        closedList[x][y] = true;

        if (x == des.first && y == des.second)
        {
            path.push_back({x, y});
            break;
        }

        for (const auto& dir : directions) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols
                && map[nx][ny] == 0 
                && closedList[nx][ny] == false)
                {
                double gNew = current.g + 1; // 상하좌우 거리 1로 가정
                double hNew = heuristic(nx, ny, des.first, des.second);
                double fNew = gNew + hNew;
                openList.push({nx, ny, fNew, gNew, hNew});
            }
        }

        path.push_back({x, y});
    }

    return path;
}

int main() {
    Map grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    vector<pair<int, int>> path = aStar({0, 0}, {4, 4}, grid);

    for (auto& p : path) {
        cout << "(" << p.first << ", " << p.second << ") -> ";
    }
    cout << "Goal\n";

    return 0;
}
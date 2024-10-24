// 토마토
// https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
#include <queue>

constexpr char VISITED = 3;
constexpr char RIPED = 2;
constexpr char NOT_RIPED = 1;
constexpr char NONE = 0;

using Box = std::vector<std::vector<std::vector<char>>>;

struct Vector3Int
{
public: int x, y, z;
bool operator==(const Vector3Int& other) { return x==other.x && y==other.y && z==other.z; }
Vector3Int Add(const Vector3Int& other) const {return Vector3Int{x+other.x, y+other.y, z+other.z}; } 
};

const Vector3Int DUMMY{1000, 1000, 1000};
const Vector3Int near[] = 
{ 
    Vector3Int{1, 0, 0}, 
    Vector3Int{-1, 0, 0},
    Vector3Int{0, 1, 0},
    Vector3Int{0, -1, 0},
    Vector3Int{0, 0, 1},
    Vector3Int{0, 0, -1},
};

// i: -1 0 1
constexpr char GetInput(const int i)
{
    return i+1;
}

bool CheckAll(const Box& tomato, const Vector3Int& bound) 
{
    for (int i=0; i<bound.x; ++i)
    {
        for (int j=0; j<bound.y; ++j)
        {
            for (int k=0; k<bound.z; ++k)
            {
                if (tomato[i][j][k] == NOT_RIPED) return false;
            }
        }
    }
    return true;
}

inline bool CheckBound(const Box& box, const Vector3Int& pos)
{
    return box.size() > pos.x && box[0].size() > pos.y && box[0][0].size() > pos.z;
}


int Ripe(Box& box, const Vector3Int& bound)
{
    std::queue<Vector3Int> q;
    int days = -1;

    for (int i=0; i<bound.x; ++i)
    {
        for (int j=0; j<bound.y; ++j)
        {
            for (int k=0; k<bound.z; ++k)
            {
                if (box[i][j][k] == RIPED ) 
                {
                    q.push(Vector3Int{i, j, k});
                    box[i][j][k] = VISITED;
                }
            }
        }
    }

    q.push(DUMMY);
    while (q.empty() == false)
    {
        auto current = q.front();
        q.pop();

        if (current == DUMMY)
        {
            days++;
            if (q.empty()) break;
            else 
            {
                q.push(DUMMY); continue;
            }
        }

        for (const auto& n : near)
        {
            auto pos = current.Add(n);
            if (CheckBound(box, pos) && box[pos.x][pos.y][pos.z] == NOT_RIPED)
            {
                box[pos.x][pos.y][pos.z] = VISITED;
                q.push(pos);
            }
        }
    }
    
    return days;
}

int solve(Box& box, const Vector3Int& bound)
{
    int days = Ripe(box, bound);

    if (CheckAll(box, bound) == false) return -1;
    else return days;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m, n, h;
    std::cin >> m >> n >> h;

    Box box(h, std::vector<std::vector<char>>(n, std::vector<char>(m)));
    for (int i=0; i<h; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<m; ++k)
            {
                int a;
                std::cin >> a;
                box[i][j][k] = GetInput(a);
            }
        }
    }

    std::cout << solve(box, Vector3Int{h, n, m}) << '\n';

    return 0;
}
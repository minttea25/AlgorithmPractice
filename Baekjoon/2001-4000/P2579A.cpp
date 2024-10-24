// 계단 오르기
// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

struct Score 
{
public:
    constexpr int Max() const { return can_go_next >= can_not_go_next ? can_go_next : can_not_go_next; }
public:
    int can_go_next; // possible to go next stair
    int can_not_go_next; // unable to go next stair
};

int memoization(const std::vector<int>& scores) 
{
    const int size = static_cast<int>(scores.size());
    
    std::vector<Score> v(size + 1);
    v[0].can_go_next = 0;
    v[0].can_not_go_next = 0;
    v[1].can_go_next = scores[0];
    v[1].can_not_go_next = scores[0];

    for (auto i=2; i<size+1; ++i)
    {
        v[i].can_go_next = v[i-2].Max() + scores[i-1];
        v[i].can_not_go_next = v[i-1].can_go_next + scores[i-1];

        std::cout << i << ": " << v[i].can_go_next << ", " << v[i].can_not_go_next << '\n';
    }

    return v[size].Max();
}


int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> scores;
    int n;
    std::cin >> n;
    for (int i=0; i<n; ++i)
    {
        int score;
        std::cin >> score;

        scores.push_back(score);
    }

    auto ans = memoization(scores);
    std::cout << ans << '\n';

    return 0;
}
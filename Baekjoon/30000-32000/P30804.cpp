// 과일 탕후루
// https://www.acmicpc.net/problem/30804

#include <iostream>
#include <vector>

constexpr const int TH = 2;

struct Mono 
{
public:
    Mono(const int _type, const int _count) : type(_type), count(_count) {}
    Mono(const Mono& other) : type(other.type), count(other.count) {}

public:
    int type;
    int count;
};

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    bool fruits[10] = {false, };
    std::vector<Mono> stick;
    int cnt = 0;

    int prev = 0;
    int current = 0;
    for (int i=0; i<n; ++i) 
    {
        std::cin >> current;
        if (prev != current)
        {
            // add new
            stick.push_back(Mono{current, 1});
        }
        else
        {
            stick.back().count++;
        }
        if (fruits[current] == false) cnt++;
        fruits[current] = true;
        prev = current;
    }

    for (int i=0; i<stick.size(); ++i)
    {
        std::cout << "[" << stick[i].type << "," << stick[i].count << "]  "; 
    }
    std::cout << '\n';


    if (cnt <= TH) 
    {
        std::cout << n << '\n';
    }
    else
    {
        const int size = stick.size();
        std::cout << size << std::endl;
        int left = 0;
        int right = 1;
        Mono types[2] = {Mono(stick[left]), Mono(stick[right])}; // copy 변경 필요 (now hard code)
        int ans = 0;
        while (right < size)
        {
            right++;
            while (right < size)
            {
                bool flag = false;
                for (int i=0; i<TH; ++i)
                {
                    if (types[i].type == stick[right].type)
                    {
                        types[i].count += stick[right].count;
                        right++;
                        flag = true;
                    }
                }
                if (flag == false) break;
            }
            std::cout << "left: " << left << '\n';
            std::cout << "right: " << right<< '\n';
            std::cout << "1: " << types[0].type << ' ' << types[0].count << '\n';
            std::cout << "2: " << types[1].type << ' ' << types[1].count << std::endl;
            ans = std::max(ans, types[0].count + types[1].count);
            std::cout << "New: " << types[0].count  << "+" <<  types[1].count << std::endl;

            bool flag = true;
            while (flag) 
            {
                for (int i=0; i<TH; ++i)
                {
                    if (stick[left].type == types[i].type)
                    {
                        types[i].count -= stick[left].count;
                        std::cout << "now count of " << types[i].type << ": " << types[i].count << '\n';
                        left++;
                        if (types[i].count == 0)
                        {
                            std::cout << "removed: " << types[i].type << std::endl;
                            types[i] = Mono(stick[right]);
                            flag = false;
                        }
                        break;
                    }
                }
            }

            std::cout << "left: " << left << '\n';
            std::cout << "right: " << right<< '\n';
            std::cout << "1: " << types[0].type << ' ' << types[0].count << '\n';
            std::cout << "2: " << types[1].type << ' ' << types[1].count << std::endl;

            std::cout << std::endl;
        }

        std::cout << ans << '\n';
    }


    return 0;
}
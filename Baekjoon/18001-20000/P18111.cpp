// 마인크래프트
// https://www.acmicpc.net/problem/18111

#include <iostream>
#include <vector>

constexpr int MAX_HEIGHT = 256;

using Land = std::vector<int>;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, b;
    std::cin >> n >> m >> b;

    int min_height = 999;
    int max_height = -1;
    Land land(MAX_HEIGHT+1, 0);
    for (int i=0; i<n*m; ++i)
    {
        int height;
        std::cin >> height;
        land[height]++;

        min_height = std::min(min_height, height);
        max_height = std::max(max_height, height);
    }

    if (min_height == max_height)
    {
        std::cout << "0 " << min_height << std::endl;
        return 0;
    }

    // check min ~ max height
    // time is first
    int ans_height = 0;
    int ans_time = 99'999'999;
    for (int i=max_height; i>=min_height; --i) // max iter: 256
    {
        int blocks = b;
        int time = 0;
        for (int ii=min_height; ii<=max_height; ++ii) // max iter: 256
        {
            if (land[ii] == 0) continue;

            int diff = i - ii;
            if (diff < 0) // first case : need 2 seconds and add blocks
            {
                time += 2 * land[ii] * diff * -1;
                blocks += diff * land[ii] * -1;
            }
            else if (diff > 0) // second case : need 1 second and remove blocks
            {
                time += 1 * land[ii] * diff;
                blocks -= diff * land[ii];
            }
            // no calculation about i == ii
        }

        // check valid
        if (blocks >= 0)
        {
            if (time < ans_time)
            {
                ans_time = time;
                ans_height = i;
            }
        }
    }

    std::cout << ans_time << ' ' << ans_height << std::endl;


    return 0;
}
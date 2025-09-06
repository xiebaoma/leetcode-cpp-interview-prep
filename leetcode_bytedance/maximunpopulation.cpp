/**
 * xiebaoma
 * 2025-09-06
 */

#include <vector>
using namespace std;

class Solution
{
private:
    static constexpr int offset = 1950; // 起始年份与起始下标之差

public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> delta(101, 0); // 变化量
        for (auto &&log : logs)
        {
            ++delta[log[0] - offset];
            --delta[log[1] - offset];
        }
        int mx = 0;   // 人口数量最大值
        int res = 0;  // 最大值对应的最小下标
        int curr = 0; // 每一年的人口数量
        // 前缀和
        for (int i = 0; i < 101; ++i)
        {
            curr += delta[i];
            if (curr > mx)
            {
                mx = curr;
                res = i;
            }
        }
        return res + offset; // 转回对应的年份
    }
};

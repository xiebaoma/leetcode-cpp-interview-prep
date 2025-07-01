/**
 * xiebaoma
 * 2025-07-01
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;  // 总盈余
        int tank = 0;   // 当前油箱
        int start = 0;  // 起点

        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            // 如果当前 tank 不够走到下一个站，重置起点
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }

        return total < 0 ? -1 : start;
    }
};

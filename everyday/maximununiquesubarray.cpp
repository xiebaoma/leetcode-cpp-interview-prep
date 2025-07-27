/**
 * xiebaoma
 * 2025-07-22
 */

#include <vector>
#include <unordered_map>
using namespace std;

//[4,2,4,5,6]
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int ret = 0;
        unordered_map<int, int> map;
        int slow = 0;
        int fast = 0;
        int sum = 0;
        while (fast < nums.size())
        {
            if (map[nums[fast]] == 0)
            {
                map[nums[fast]]++;
                ret += nums[fast];
                sum = max(sum,ret);
                fast++;
            }
            else
            {
                sum = max(sum, ret);
                while (map[nums[fast]] > 0)
                {
                    map[nums[slow]]--;
                    ret -= nums[slow];
                    slow++;
                }
                map[nums[fast]]++;
                ret += nums[fast];
                fast++;
            }
        }
        return sum;
    }
};
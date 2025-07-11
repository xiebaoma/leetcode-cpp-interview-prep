/**
 * xiebaoma
 * 2025-07-11
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        bool ret = false;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) == map.end())
            {
                map[nums[i]] = i;
            }
            else
            {
                if (i - map[nums[i]] <= k)
                {
                    ret = true;
                    break;
                }
                else
                {
                    map[nums[i]] = i;
                }
            }
        }
        return ret;
    }
};
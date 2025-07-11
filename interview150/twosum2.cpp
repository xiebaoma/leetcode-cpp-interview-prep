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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                ret.push_back(map[target - nums[i]]);
                ret.push_back(i);
                break;
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return ret;
    }
};
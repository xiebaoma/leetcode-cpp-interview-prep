/**
 * xiebaoma
 * 2025-11-23
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> map;
        for (int i= 0; i<nums.size();i++)
        {
            int val = target-nums[i];
            if (map.find(val)!=map.end())
            {
                res.push_back(map[val]);
                res.push_back(i);
                break;
            }
            map[nums[i]]=i;
        }
        return res;
    }
};
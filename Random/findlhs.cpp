/**
 * xiebaoma
 * 2025-06-30
 */

#include <vector>
#include <algorithm>
using namespace std;

//[1,1,1,1]
//[1,3,5,7,9,11,13,15,17]
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int slow = 0;
        int fast = 0;
        int len = nums.size();
        if (nums[len - 1] == nums[0])
        {
            return 0;
        }
        while (fast < len)
        {
            if(nums[fast]==nums[slow])
            {
                fast++;
            }else if(nums[fast]==nums[slow]+1){
                ret=max(ret,fast-slow+1);
                fast++;
            }else{
                slow++;
            }
        }
        return ret;
    }
};
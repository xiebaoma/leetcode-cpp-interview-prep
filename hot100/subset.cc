/**
 * xiebaoma
 * 2025-12-18
 */

#include <vector>
using namespace std;


/**
* 输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
[[],[1],[2],[3],[1,2],[1,3],[2,2],[2,3],[3,2],[3,3],[1,2,3],[1,3,3],[2,2,3],[2,3,3],[3,2,3],[3,3,3]]
 */
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> cur;

    void backtrace(int index, vector<int>& nums)
    {
        if (index==nums.size())
        {
            ret.push_back(cur);
            return;
        }
        //不选
        backtrace(index+1,nums);
        //选
        cur.push_back(nums[index]);
        backtrace(index+1,nums);
        cur.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        backtrace(0,nums);
        return ret;
    }
};
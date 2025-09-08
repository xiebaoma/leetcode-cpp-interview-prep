/**
 * xiebaoma
 * 2025-09-08
 */

#include <vector>
using namespace std;

// 输入：nums = [4,3,2,7,8,2,3,1]
// 输出：[5,6]
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();

        // 遍历数组，标记出现过的数字
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1; // 映射到索引
            if (nums[index] > 0)
            {
                nums[index] = -nums[index]; // 标记为负数
            }
        }

        // 找出没被标记的索引 + 1，就是缺失的数字
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

/**
 * xiebaoma
 * 2025-08-25
 */

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;

        // 可以提前排除掉大于target的数
        for (int num : nums)
        {
            if (num > target)
                return false;
        }

        // 排序（倒序），有助于更快剪枝
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> bucket(k, 0); // 每个桶当前的和
        return backtrack(nums, 0, bucket, target, k);
    }

private:
    bool backtrack(vector<int> &nums, int index, vector<int> &bucket, int target, int k)
    {
        if (index == nums.size())
        {
            // 所有数字都分配完毕，检查是否每个bucket都等于target
            for (int sum : bucket)
            {
                if (sum != target)
                    return false;
            }
            return true;
        }

        int num = nums[index];
        for (int i = 0; i < k; ++i)
        {
            // 如果当前桶加上这个数字会超过target，跳过
            if (bucket[i] + num > target)
                continue;

            // 剪枝：如果当前桶和前一个桶的值一样，且前一个桶没放这个数，那当前桶也没必要放
            if (i > 0 && bucket[i] == bucket[i - 1])
                continue;

            bucket[i] += num;
            if (backtrack(nums, index + 1, bucket, target, k))
            {
                return true;
            }
            bucket[i] -= num; // 回溯

            // 如果当前数字放入当前桶后，bucket[i] == 0，说明它没起到作用，且后续也无法分配 → 剪枝
            if (bucket[i] == 0)
                break;
        }

        return false;
    }
};
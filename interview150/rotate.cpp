/**
 * xiebaoma
 * 2025-06-29
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        k = k % len;
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < k / 2; i++)
        {
            swap(nums[i], nums[k - i - 1]);
        }
        for (int i = k; i < (len + k) / 2; i++)
        {
            swap(nums[i], nums[len + k - i - 1]);
        }
    }
};
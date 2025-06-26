/**
 * xiebaoma
 * 2025-06-26
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int zero = -1;
        int notzero = 0;
        while (notzero < len)
        {
            if (nums[notzero] != 0)
            {
                zero++;
                swap(nums[zero], nums[notzero]);
            }
            notzero++;
        }
    }
};
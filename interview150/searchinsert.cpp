/**
 * xiebaoma
 * 2025-08-04
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while (left <= right)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            mid = left + (right - left) / 2;
        }
        return left;
    }
};
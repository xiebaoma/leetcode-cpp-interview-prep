/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // left 是插入位置
    return left;
}

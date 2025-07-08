/**
 * xiebaoma
 * 2025-07-08
 */

#include <vector>
using namespace std;

//[4,5,6,7,0,1,2]
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // 比右边大，最小值在右半边
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // 比右边小，最小值在左半边（包括 mid）
            else {
                right = mid;
            }
        }

        // 循环结束，left == right，指向最小值
        return nums[left];
    }
};
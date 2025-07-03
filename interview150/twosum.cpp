/**
 * xiebaoma
 * 2025-07-03
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int midfind(int left, int right, vector<int> &nums, int target)
    {
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
        return -1;
    }

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int index = 0;
        int len = numbers.size();
        vector<int> ret(2);
        while (index < len - 1)
        {
            int left = index + 1;
            int right = len - 1;
            int tar = target - numbers[index];
            int index2 = midfind(left, right, numbers, tar);
            if (index2 != -1 )
            {
                ret[0] = index + 1;
                ret[1] = index2 + 1;
                break;
            }
            index++;
        }
        return ret;
    }
};
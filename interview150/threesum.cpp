/**
 * xiebaoma
 *
 */

#include <vector>
#include <algorithm>
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        int i = 0;
        int len = nums.size();
        while (i < len - 2 && nums[i] <= 0)
        {
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int j = i + 1;
            if (nums[i] + nums[j] > 0)
            {
                break;
            }
            while (j < len - 1)
            {
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                int left = j + 1;
                int right = len - 1;
                int tar = -(nums[i] + nums[j]);
                int k = midfind(left, right, nums, tar);
                if (k != -1)
                {
                    vector<int> num(3);
                    num[0] = nums[i];
                    num[1] = nums[j];
                    num[2] = nums[k];
                    ret.push_back(num);
                }
                j++;
            }
            i++;
        }
        return ret;
    }
};
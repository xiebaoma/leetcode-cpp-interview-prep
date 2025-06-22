/**
 * xiebaoma
 * 2025-06-22
 */

#include <vector>
using namespace std;

// nums1 = [3,2,0,1,0], nums2 = [6,5,0]
// nums1 = [2,0,2,0], nums2 = [1,4]
class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0;
        int count01 = 0;
        int len1 = nums1.size();
        long long sum2 = 0;
        int count02 = 0;
        int len2 = nums2.size();
        long long ret = 0;
        for (int i = 0; i < len1; i++)
        {
            if (nums1[i] == 0)
                count01++;
            else
                sum1 += nums1[i];
        }
        for (int i = 0; i < len2; i++)
        {
            if (nums2[i] == 0)
                count02++;
            else
                sum2 += nums2[i];
        }

        if (count01 > 0 && count02 > 0)
        {
            ret = max(sum1 + count01, sum2 + count02);
        }
        else if (count01 == 0 && count02 > 0)
        {
            if ((sum1 - sum2) < count02)
            {
                ret = -1;
            }
            else
            {
                ret = sum1;
            }
        }
        else if (count01 > 0 && count02 == 0)
        {
            if ((sum2 - sum1) < count01)
            {
                ret = -1;
            }
            else
            {
                ret = sum2;
            }
        }
        else
        {
            if (sum1 == sum2)
                ret = sum1;
            else
                ret = -1;
        }
        return ret;
    }
};
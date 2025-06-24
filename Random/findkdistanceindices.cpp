/**
 * xiebaoma
 * 2025-06-24
 */

#include <vector>
using namespace std;

//[2,2,2,2,2,2] 2 2
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ret;
        int i = 0;
        int len = nums.size();
        while (i < len)
        {
            for (int j = i - k; j <= k + i; j++)
            {
                if (j < 0 || j >= len)
                {
                    continue;
                }
                if (nums[j] == key)
                {
                    ret.push_back(i);
                    break;
                }
            }
            i++;
        }
        return ret;
    }
};
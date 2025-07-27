/**
 * xiebaoma
 * 2025-06-28
 * 不难，但是考查stl的API考得还挺多
 */

#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> ret;
        for (int val : nums)
        {
            if (ret.size() < k)
            {
                ret.push_back(val);
            }
            else
            {
                auto it = min_element(ret.begin(), ret.end());
                if (val > *it)
                {
                    ret.erase(it);
                    ret.push_back(val);
                }
            }
        }
        return ret;
    }
};
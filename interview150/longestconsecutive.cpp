/**
 * xiebaoma
 * 2025-07-11
 */

#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        set<int> mset;
        for (int i : nums)
        {
            mset.emplace(i);
        }
        int count = 0;
        int ret = 1;
        for (int i : mset)
        {
            if (mset.count(i - 1))
            {
                count++;
                ret = max(ret, count);
            }
            else
            {
                ret = max(ret, count);
                count = 1;
            }
        }
        return ret;
    }
};
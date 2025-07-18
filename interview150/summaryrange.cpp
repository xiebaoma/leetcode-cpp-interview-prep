/**
 * xiebaoma
 * 2025-07-18
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        vector<string> ret;
        while (fast < len)
        {
            if (fast == len - 1 || (fast + 1 < len && nums[fast + 1] != nums[fast] + 1))
            {
                string s = "";
                if (fast > slow)
                {
                    int i = nums[slow];
                    int j = nums[fast];
                    s += to_string(i);
                    s += "->";
                    s += to_string(j);
                }
                else
                {
                    s += to_string(nums[slow]);
                }
                ret.push_back(s);
                fast++;
                slow = fast;
            }
            else
            {
                fast++;
            }
        }
        return ret;
    }
};
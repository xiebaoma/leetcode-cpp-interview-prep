/**
 * xiebaoma
 * 2025-06-30
 */

#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        int index = 0;
        while (index < len)
        {
            int steps = nums[index];
            if (steps == 0 && index < len - 1)
            {
                return false;
            }
            if (index + steps >= len-1)
                return true;
            int farest = index+1;
            for (int i = index+1; i <= steps + index; i++)
            {
                if(i+ nums[i]>farest+ nums[farest]){
                    farest=i;
                }
            }
            index=farest;
        }
        return false;
    }
};
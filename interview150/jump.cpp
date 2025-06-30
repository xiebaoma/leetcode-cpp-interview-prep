/**
 * xiebaoma
 * 2025-06-30
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        if(len==1){
            return 0;
        }
        int index = 0;
        int count = 0;
        while (index < len)
        {
            int steps = nums[index];
            if (index + steps >= len - 1)
                return count + 1;
            int farest = index + 1;
            for (int i = index + 1; i <= steps + index; i++)
            {
                if (i + nums[i] > farest + nums[farest])
                {
                    farest = i;
                }
            }
            count++;
            index = farest;
        }
        return count;
    }
};
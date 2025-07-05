/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
#include <algorithm>
using namespace std;

// 2,2,3,4
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        int i = len - 1;
        int val = arr[i];
        int count = 0;
        int ret = -1;
        while (i >= 0)
        {
            if (arr[i] == val)
            {
                count++;
            }
            else
            {
                if (count == val)
                {
                    ret = val;
                    break;
                }
                else
                {
                    val = arr[i];
                    count = 1;
                }
            }
            i--;
        }
        if (count == val)
        {
            ret = val;
        }
        return ret;
    }
};
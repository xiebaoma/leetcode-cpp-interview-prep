/**
 * xiebaoma
 * 2025-07-01
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int len = ratings.size();
        vector<int> vec(len);
        int index = 0;
        while (index < len)
        {
            if (index == 0)
            {
                vec[index] = 1;
            }
            else if (ratings[index] > ratings[index - 1])
            {
                vec[index] = vec[index-1] + 1;
            }
            else if (ratings[index] == ratings[index - 1])
            {
                vec[index] = 1;
            }
            else
            {
                vec[index] = 1;
                int i = index - 1;
                while (i >= 0 && vec[i] == vec[i + 1] && ratings[i]>ratings[i+1])
                {
                    vec[i]++;
                    i--;
                }
            }
            index++;
        }
        int ret = 0;
        for (int val : vec)
        {
            ret += val;
        }
        return ret;
    }
};
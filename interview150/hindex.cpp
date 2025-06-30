/**
 * xiebaoma
 * 2025-06-30
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        int ret = 0;
        for (int i = 0; i < len; i++)
        {
            if (citations[len - i - 1] >= i + 1)
            {
                ret = i + 1;
            }
            else
            {
                break;
            }
        }
        return ret;
    }
};
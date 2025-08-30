/**
 * xiebaoma
 * 2025-08-30
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int takeAttendance(vector<int> &records)
    {
        int i = 0, j = records.size() - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (records[m] == m)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

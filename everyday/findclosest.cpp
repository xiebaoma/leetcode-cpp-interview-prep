/**
 * xiebaoma
 * 2025-09-04
 */

#include <cmath>
using namespace std;

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int dxz = abs(x - z), dyz = abs(y - z);
        if (dxz < dyz)
        {
            return 1;
        }
        else if (dxz > dyz)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
};

/**
 * xiebaoma
 * 2025-06-28
 */

#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int i = 0;
        int len = flowerbed.size();
        for (i = 0; i < len; i++)
        {
            if (n == 0)
                return true;
            if (flowerbed[i] == 0)
            {
                if (i - 1 >= 0 && flowerbed[i - 1] == 1)
                    continue;
                if (i + 1 < len && flowerbed[i + 1] == 1)
                    continue;
                flowerbed[i] = 1;
                n--;
            }
        }
        return n==0;
    }
};
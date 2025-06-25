/**
 * xiebaoma
 * 2025-06-25
 */

#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isuglynumber(int num, int a, int b, int c)
    {
        return num % a == 0 || num % b == 0 || num % c == 0;
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int count = 0;
        int start = min({a, b, c});
        int num = start;
        while (count < n)
        {
            if (isuglynumber(num, a, b, c))
            {
                count++;
            }
            num++;
        }
        return num - 1;
    }
};
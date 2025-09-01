/**
 * xiebaoma
 * 2025-09-01
 */

class Solution
{
public:
    int smallestEvenMultiple(int n)
    {
        return n % 2 == 0 ? n : 2 * n;
    }
};

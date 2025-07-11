/**
 * xiebaoma
 * 2025-07-11
 */
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int change(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            int x = n % 10;
            n /= 10;
            ret += x * x;
        }
        return ret;
    }
    bool isHappy(int n)
    {
        unordered_set<int> set;
        bool ishappy = false;
        while (true)
        {
            if (n == 1)
            {
                ishappy = true;
                break;
            }
            if (set.find(n) == set.end())
            {
                set.emplace(n);
            }
            else
            {
                break;
            }
            n = change(n);
        }
        return ishappy;
    }
};
/**
 * xiebaoma
 * 2025-06-25
 * 使用迭代比使用递归要快
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 1;
        }
        vector<int> tri;
        tri.push_back(0);
        tri.push_back(1);
        tri.push_back(1);
        for (int i = 3; i <= n; i++)
        {
            tri.push_back(tri[i - 1] + tri[i - 2] + tri[i - 3]);
        }
        return tri[n - 1];
    }
};
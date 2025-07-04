/**
 * xiebaoma
 * 2025-07-04
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        long long i = k - 1, cnt = 0;
        while (i)
        {
            int n = log2(i);
            cnt += operations[n];
            i -= 1ll << n;
        }
        return cnt % 26 + 'a';
    }
};

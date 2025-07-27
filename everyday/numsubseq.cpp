/**
 * xiebaoma
 * 2025-06-29
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

    // 快速幂计算 (base^exp) % MOD
    int fastPow(int base, int exp)
    {
        long long res = 1;
        long long b = base;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * b) % MOD;
            b = (b * b) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int result = 0;

        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                result = (result + fastPow(2, r - l)) % MOD;
                l++;
            }
            else
            {
                r--;
            }
        }

        return result;
    }
};

/**
 * xiebaoma
 * 2025-06-25
 * 数学要求高
 */

#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    ll gcd(ll a, ll b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll lcm(ll a, ll b)
    {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c)
    {
        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ac = lcm(a, c);
        ll abc = lcm(a, bc);

        auto count = [&](ll x)
        {
            return x / a + x / b + x / c - x / ab - x / bc - x / ac + x / abc;
        };

        ll left = 1, right = 2e9, ans = -1;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (count(mid) >= n)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

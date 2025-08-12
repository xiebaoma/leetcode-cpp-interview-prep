/**
 * xiebaoma
 * 2025-08-12
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ret;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int num = digits[i] + carry;
            if (i == digits.size()-1)
            {
                num += 1;
            }
            carry = num / 10;
            num = num % 10;
            ret.push_back(num);
        }
        if (carry == 1)
        {
            ret.push_back(carry);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
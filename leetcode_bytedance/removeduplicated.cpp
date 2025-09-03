/**
 * xiebaoma
 * 2025-09-03
 */

#include <string>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string stk;
        for (char ch : s)
        {
            if (!stk.empty() && stk.back() == ch)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};

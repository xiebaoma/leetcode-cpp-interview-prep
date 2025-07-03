/**
 * xiebaoma
 * 2025-07-03
 */

#include <string>
using namespace std;

class Solution
{
public:
    char kthCharacter(int k)
    {
        string s = "a";
        while (s.size() < k)
        {
            string next = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == 'z')
                {
                    next += 'a';
                }
                else
                {
                    next += (s[i] + 1);
                }
            }
            s += next;
        }
        return s[k - 1];
    }
};
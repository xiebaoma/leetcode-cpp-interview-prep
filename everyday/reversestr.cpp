/**
 * xiebaoma
 * 2025-6-23
 */

#include <string>
using namespace std;

// abcd 4
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        string ret = "";
        int index = 0;
        int len = s.size();
        while (true)
        {
            if (index + k - 1 < len)
            {
                for (int i = index + k - 1; i >= index; i--)
                {
                    char c = s[i];
                    ret += c;
                }
                index += k;
            }
            else
            {
                for (int i = len - 1; i >= index; i--)
                {
                    char c = s[i];
                    ret += c;
                }
                return ret;
            }
            if (index + k - 1 < len)
            {
                for (int i = index; i < index + k; i++)
                {
                    char c = s[i];
                    ret += c;
                }
                index += k;
            }
            else
            {
                for (int i = index; i < len; i++)
                {
                    char c = s[i];
                    ret += c;
                }
                return ret;
            }
        }
        return ret;
    }
};
/**
 * xiebaoma
 * 2025-07-01
 */

#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ret = 0;
        int i = 0;
        int len = s.length();
        while (i < len)
        {
            if (s[i] == 'I')
            {
                if (i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                {
                    ret-=1;
                }else{
                    ret+=1;
                }
            }
            else if (s[i] == 'V')
            {
                ret+=5;
            }
            else if (s[i] == 'X')
            {
                if (i + 1 < len && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                {
                    ret-=10;
                }else{
                    ret+=10;
                }
            }
            else if (s[i] == 'L')
            {
                ret+=50;
            }
            else if (s[i] == 'C')
            {
                if (i + 1 < len && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                {
                    ret-=100;
                }else{
                    ret+=100;
                }
            }
            else if (s[i] == 'D')
            {
                ret+=500;
            }
            else if (s[i] == 'M')
            {
                ret+=1000;
            }
            i++;
        }
        return ret;
    }
};
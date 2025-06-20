/**
 * xiebaoma
 * 2025-6-20
 */

#include <string>
using namespace std;

class Solution
{
public:
    string binstr(int i)
    {
        string res = "";
        while (i > 0)
        {
            res = (i % 2 == 1 ? '1' : '0') + res;
            i/=2;
        }
        return res;
    }

    bool queryString(string s, int n)
    {
        for (int i = 1; i <= n; i++)
        {
            string substr = binstr(i);
            if(s.find(substr) == std::string::npos){
                return false;
            }
        }
        return true;
    }
};
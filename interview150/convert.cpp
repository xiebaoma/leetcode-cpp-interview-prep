/**
 * xiebaoma
 * 2025-07-02
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> ret(numRows, "");
        int i = 0;
        int len = s.size();
        if (numRows == 1)
        {
            return s;
        }
        bool isdown = true;
        int row = 0;
        while (i < len)
        {
            char c = s[i];
            ret[row] += c;
            if (row < numRows - 1 && isdown)
            {
                row++;
            }
            else if (row == numRows - 1)
            {
                isdown = false;
                row--;
            }
            else if (row > 0 && !isdown)
            {
                row--;
            }
            else
            {
                isdown = true;
                row++;
            }
            i++;
        }
        string str = "";
        for (string s : ret)
        {
            str += s;
        }
        return str;
    }
};
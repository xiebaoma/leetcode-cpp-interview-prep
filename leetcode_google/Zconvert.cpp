/**
 * xiebaoma
 * 2025-06-20
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(numRows==1){
            return s;
        }
        vector<string> vec(numRows, "");

        int index = 0;
        bool down = true;
        string ret = "";
        for (int i = 0; i < s.size(); i++)
        {
            char val = s[i];
            vec[index] += val;
            if (down)
            {
                if (index == numRows - 1)
                {
                    index--;
                    down = false;
                }
                else
                {
                    index++;
                }
            }
            else
            {
                if (index == 0)
                {
                    index++;
                    down = true;
                }
                else
                {
                    index--;
                }
            }
        }
        for (string str : vec)
        {
            ret += str;
        }
        return ret;
    }
};

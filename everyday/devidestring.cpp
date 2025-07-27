/**
 * xiebaoma
 * 2025-06-22
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string> ret;
        int index = 0;
        int len = s.size();
        while (index < len)
        {
            string str = s.substr(index, k);
            ret.push_back(str);
            index += k;
        }
        string &laststr = ret[ret.size() - 1];
        while (laststr.length() < k)
        {
            laststr += fill;
        }
        return ret;
    }
};
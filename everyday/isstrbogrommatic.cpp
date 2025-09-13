/**
 * xiebaoma
 * 2025-09-13
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        unordered_map<char, char> rotate{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

        for (int i = 0; i <= num.size() / 2; i++)
        {
            if (!rotate.count(num[i]))
            {
                return false;
            }
            if (rotate[num[i]] != num[num.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

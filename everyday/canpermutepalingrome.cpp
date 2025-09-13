/**
 * xiebaoma
 * 2025-09-13
 */

#include <string>
using namespace std;

class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        int map[128] = {0};
        for (char c : s)
        {
            map[c]++;
        }
        int count = 0;
        for (int i = 0; i < 128 && count <= 1; i++)
        {
            count += map[i] % 2;
        }
        return count <= 1;
    }
};

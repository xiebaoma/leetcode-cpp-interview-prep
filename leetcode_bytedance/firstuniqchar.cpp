/**
 * xiebaoma
 * 2025-09-17
 */

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int H[26] = {0};
        for (auto c : s)
        {
            H[c - 'a']++;
        }
        int i = 0;
        for (auto c : s)
        {
            if (H[c - 'a'] == 1)
                return i;
            i++;
        }
        return -1;
    }
};
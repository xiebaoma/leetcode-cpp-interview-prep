/**
 * xiebaoma
 * 2025-07-09
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mmap;
        for (char c : magazine)
        {
            mmap[c]++;
        }
        for (char c : ransomNote)
        {
            mmap[c]--;
            if (mmap[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
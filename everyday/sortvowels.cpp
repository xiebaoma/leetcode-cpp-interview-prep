/**
 * xiebaoma
 * 2025-09-11
 */

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

public:
    string sortVowels(string s)
    {
        vector<int> cnt(58, -1);
        for (char ch : vowels)
        {
            cnt[ch - 'A'] = 0;
        }

        for (char ch : s)
        {
            int i = ch - 'A';
            if (cnt[i] != -1)
            {
                cnt[i]++;
            }
        }

        int idx = 0;
        for (char &ch : s)
        {
            int i = ch - 'A';
            if (cnt[i] != -1)
            {
                while (cnt[idx] <= 0)
                {
                    idx++;
                }
                ch = (char)(idx + 'A');
                cnt[idx]--;
            }
        }

        return s;
    }
};

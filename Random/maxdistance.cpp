/**
 * xiebaoma
 * 2025-6-20
 */

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int countn = 0;
        int counts = 0;
        int countw = 0;
        int counte = 0;
        int ret = 0;
        for (char c : s)
        {
            if (c == 'N')
                countn++;
            if (c == 'S')
                counts++;
            if (c == 'W')
                countw++;
            if (c == 'E')
                counte++;

            int times1 = min({countn, counts, k});
            int times2 = min({countw, counte, k - times1});

            int x = abs(countn - counts) + times1 * 2;
            int y = abs(countw - counte) + times2 * 2;
            ret = max(ret, x + y);
        }
        return ret;
    }
};
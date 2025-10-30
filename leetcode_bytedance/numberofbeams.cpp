/**
 * xiebaoma
 * 2025-10-29
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0, ans = 0;
        for (const string& line: bank) {
            int cnt = count_if(line.begin(), line.end(), [](char ch) {return ch == '1';});
            if (cnt != 0) {
                ans += last * cnt;
                last = cnt;
            }
        }
        return ans;
    }
};

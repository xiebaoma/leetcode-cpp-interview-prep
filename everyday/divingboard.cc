/**
 * xiebaoma
 * 2025-12-08
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        int len = shorter * k;
        ans.push_back(len);
        for(int i = 1; i <= k; i++) {
            len -= shorter;
            len += longer;
            if (ans.back()!=len)
            {
                ans.push_back(len);
            }
        }
        return ans;
    }
};
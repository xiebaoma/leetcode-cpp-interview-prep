/**
 * xiebaoma
 * 2025-12-12
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows==0) return res;
        res.push_back({1});
        if (numRows==1) return res;
        res.push_back({1,1});
        for (int i=2;i<numRows;i++)
        {
            vector<int> cur;
            cur.push_back(1);
            for (int j=1;j<=i-1;j++)
            {
                cur.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};
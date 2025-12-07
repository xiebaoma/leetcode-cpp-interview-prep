/**
 * xiebaoma
 * 2025-12-03
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        if (intervals.size()==0)
        {
            return res;
        }
        int first=intervals[0][0];
        int second=intervals[0][1];
        for (int i=1;i<intervals.size();i++)
        {
            int cur1=intervals[i][0];
            int cur2=intervals[i][1];
            if (cur1>second)
            {
                res.push_back({first,second});
                first=cur1;
                second=cur2;
            }else
            {
                second = max(second, cur2);
            }
        }
        res.push_back({first,second});
        return res;
    }
};
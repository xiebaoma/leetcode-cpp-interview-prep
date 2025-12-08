/**
 * xiebaoma
 * 2025-12-08
 */

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> q;
        for (int i=0;i<k;i++)
        {
            q.push({nums[i],i});
        }
        res.push_back(q.top().first);
        for (int i=k;i<nums.size();i++)
        {
            q.push({nums[i],i});
            while (q.top().second<=i-k)
            {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};
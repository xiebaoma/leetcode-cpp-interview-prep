/**
 * xiebaoma
 * 2025-08-24
 */

#include<vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = nums[i] ? pre[i - 1] + 1 : 0; 
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = nums[i] ? suf[i + 1] + 1 : 0;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int preSum = i == 0 ? 0 : pre[i - 1];
            int sufSum = i == n - 1 ? 0 : suf[i + 1];
            ans = max(ans, preSum + sufSum);
        }

        return ans;
    }
};

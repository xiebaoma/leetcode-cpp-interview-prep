/**
 * xiebaoma
 * 2025-12-11
 */

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> res(n);
        if (n==0)
        {
            return res;
        }
        left[0]=1;
        for (int i=1;i<n;i++)
        {
            left[i]=nums[i-1]*left[i-1];
        }
        right[n-1]=1;
        for (int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for (int i=0;i<n;i++)
        {
            res[i]=left[i]*right[i];
        }
        return res;
    }
};
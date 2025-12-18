/**
 * xiebaoma
 * 2025-12-18
 */

#include <vector>
using namespace std;

class Solution {
public:

    bool check(vector<int>& nums, int target)
    {
        int l = 0;
        int r= nums.size()-1;
        while (l<=r)
        {
            int mid = l+(r-l)/2;
            if (nums[mid]==target) return true;
            if (nums[mid]>target)
            {
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0;i<matrix.size();i++)
        {
            if (check(matrix[i],target)) return true;
            if (matrix[i][0]>target) return false;
        }
        return false;
    }
};
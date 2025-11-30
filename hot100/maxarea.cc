/**
 * xiebaoma
 * 2025-11-28
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int l=0;
        int r= height.size()-1;
        while (l<r)
        {
            int h=min(height[r],height[l]);
            int cur= (r-l)*h;
            res=max(cur,res);
            if (height[r]<height[l])
            {
                r--;
            }else
            {
                l++;
            }
        }
        return res;
    }
};
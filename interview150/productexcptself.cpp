/**
 * xiebaoma
 * 2025-07-01
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len);
        vector<int> right(len);
        left[0]=1;
        right[len-1]=1;
        for(int i=1;i<len;i++){
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=len-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
        vector<int> ret;
        for(int i=0;i<len;i++){
            ret.push_back(left[i]*right[i]);
        }
        return ret;
    }
};
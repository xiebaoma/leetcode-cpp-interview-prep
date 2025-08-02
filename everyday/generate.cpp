/**
 * xiebaoma
 * 2025-08-01
 */

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows<=0){
            return ret;
        }
        vector<int> temp={1};
        ret.push_back(temp);
        if(numRows==1){
            return ret;
        }
        temp={1,1};
        ret.push_back(temp);
        if(numRows==2){
            return ret;
        }
        for(int i=2;i<numRows;i++){
            vector<int> nums;
            nums.push_back(1);
            for(int j=1;j<i;j++){
                nums.push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            nums.push_back(1);
            ret.push_back(nums);
        }
        return ret;
    }
};
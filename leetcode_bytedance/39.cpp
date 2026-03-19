#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int id, vector<int>& cur, int sum, int target){
        if(target==sum){
            res.push_back(cur);
        }else if(sum>target || id>=nums.size()){

        }else{
            cur.push_back(nums[id]);
            sum+=nums[id];
            dfs(nums,id+1,cur,sum,target);
            sum-=nums[id];
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        dfs(candidates,0,cur,0,target);
        return res;
    }
};
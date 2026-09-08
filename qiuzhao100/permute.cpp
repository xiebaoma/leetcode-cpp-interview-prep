#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n= nums.size();
        vector<bool> used(n, false);
        dfs(res, path, nums,used);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==false){
                used[i]=true;
                path.push_back(nums[i]);
                dfs(res, path, nums, used);
                path.pop_back();
                used[i]=false;
            }
        }
    }
};
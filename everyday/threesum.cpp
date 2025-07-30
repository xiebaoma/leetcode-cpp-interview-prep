#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> findtwosum(vector<int>& nums,int start, int target)
{
    unordered_map<int,int> map;
    vector<int> ret;
    for(int i= start;i<nums.size();i++)
    {
        if(map.count(target-nums[i]))
        {
            ret.push_back(map[target-nums[i]]);
            ret.push_back(i);
            return ret;
        }
        map[nums[i]]=i;
    }
    return ret;
}

vector<vector<int>> findarray(vector<int>& nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0;i<n-2;i++)
    {
        int val = nums[i];
        int target= 1-val;
        vector<int> vec = findtwosum(nums,i+1,target);
        if(vec.size()==2){
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[vec[0]]);
            temp.push_back(nums[vec[1]]);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums={};
    vector<vector<int>> ans= findarray(nums);
    for(int i=0; i<ans.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}
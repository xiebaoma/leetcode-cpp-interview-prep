#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nmap;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int v= nums[i];
            if(nmap.find(target-v)!=nmap.end()){
                int j= nmap[target-v];
                res.push_back(j);
                res.push_back(i);
                return res;
            }
            nmap[v]=i;
        }
        return res;
    }
};
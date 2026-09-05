#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nset;
        for(int n: nums){
            nset.emplace(n);
        }
        int res=0;
        for(int n: nset){
            if(nset.find(n-1)!=nset.end()){
                continue;
            }
            int i=1;
            while(nset.find(n+1)!=nset.end()){
                i++;
                n++;
            }
            res=max(res,i);
        }
        return res;
    }
};
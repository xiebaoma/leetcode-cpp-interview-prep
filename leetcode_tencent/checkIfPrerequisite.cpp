#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& pre, unordered_map<int, unordered_set<int>>& classmap, int root, int cur){
        vector<int>& next=pre[cur];
        for(int n: next){
            classmap[root].emplace(n);
            dfs(pre,classmap,root,n);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> pre;
        for(vector<int>& vec:prerequisites){
            pre[vec[0]].push_back(vec[1]);
        }
        unordered_map<int,unordered_set<int>> classmap;
        for(int i = 0; i < numCourses; i++){
            dfs(pre, classmap, i, i);
        }
        vector<bool> res;
        for(vector<int>& vec:queries){
            if(classmap[vec[0]].find(vec[1])!=classmap[vec[0]].end()){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};
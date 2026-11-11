#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出：[20,24]
解释：
列表 1 中的 24 落在 [20,24] 内
列表 2 中的 20 落在 [20,24] 内
列表 3 中的 22 落在 [20,24] 内
*/

vector<int> miniinterval(vector<vector<int>>& nums){
    vector<int> res(2);
    int mininterval=-1;
    int m= nums.size();
    vector<int> vec(m,0);
    priority_queue<int, vector<int>, greater<int>> smallpq;
    priority_queue<int> bigpq;
    for(int i=0;i<nums.size();i++){
        smallpq.push(nums[i][0]);
        bigpq.push(nums[i][0]);
    }
    int miniinterval=bigpq.top()-smallpq.top();
    res[0]=smallpq.top();
    res[1]=bigpq.top();
    while(true){
        for(int i=0;i<vec.size();i++){
            int id= vec[i];
            if(nums[i][id]==smallpq.top()){
                smallpq.pop();
                vec[i]++;
                if(vec[i]== nums[i].size()){
                    return res;
                }
                smallpq.push(nums[i][vec[i]]);
                bigpq.push(nums[i][vec[i]]);
                
                int inter= bigpq.top()-smallpq.top();
                if(inter<miniinterval){
                    miniinterval=inter;
                    res[0]=smallpq.top();
                    res[1]=bigpq.top();
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> nums;
    nums.push_back({4,10,15,24,26});
    nums.push_back({0,9,12,20});
    nums.push_back({5,18,22,30});
    vector<int> res= miniinterval(nums);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}
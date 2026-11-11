#include <vector>
#include <iostream>
using namespace std;

vector<int> func(vector<vector<int>>& nums){
    vector<int> res;
    int m= nums.size();
    int n= nums[0].size();
    vector<vector<bool>> isvisit(m, vector<bool>(n, false));
    // 1 2 3 4
    int i=0;
    int j=0;
    int index=1;//
    while(true){
        if(i>=0 && i<m && j>=0 && j<n && isvisit[i][j]==false){
            int val= nums[i][j];
            res.push_back(val);
            isvisit[i][j]=true;
        }else{
            break;
        }
        
        if(index==1){
            //i+1 j
            if(i+1 < m && isvisit[i+1][j]==false){
                i++;
            }else{
                j++;
                index=2;
            }
        }else if(index==2){
            if(j+1 < n && isvisit[i][j+1]==false){
                j++;
            }else{
                i--;
                index=3;
            }
        }else if(index==3){
            if(i-1 >=0 && isvisit[i-1][j]==false){
                i--;
            }else{
                j--;
                index=4;
            }
        }else if(index==4){
            if(j-1 >=0 && isvisit[i][j-1]==false){
                j--;
            }else{
                i++;
                index=1;
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int>> nums;
    nums.push_back({1,2,3});
    nums.push_back({4,5,6});
    nums.push_back({7,8,9});
    vector<int> res= func(nums);
    for(int i=0;i<res.size();i++){
        cout<< res[i]<< " ";
    }
    return 0;
}
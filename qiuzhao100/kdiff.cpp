#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int kdiff(vector<int>& vec, int k){
    int res=0;
    for(int i=0;i<= vec.size()-k;i++){
        unordered_set<int> nums;
        for(int j=i;j< vec.size();j++){
            nums.emplace(vec[j]);
            if(nums.size()==k){
                res++;
            }else if(nums.size()>k){
                break;
            }
        }
    }
    return res;
}

int main(){
    vector<int> vec={1,2,1,3,4};
    int res= kdiff(vec, 3);
    cout << "res="<< res<<endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int Count(vector<int>& nums, int target){
    int n =nums.size();
    if(n==0){
        return 0;
    }
    int res=0;

    int left=0;
    int right=n-1;
    int l=-1;
    int r=-1;

    while(left<=right){
        int mid= left+(right-left)/2;
        if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            l=mid;
            right=mid-1;
        }
    }

    left=0;
    right=n-1;
    while(left<=right){
        int mid= left+(right-left)/2;
        if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            r=mid;
            left=mid+1;
        }
    }
    if(r==-1){
        return 0;
    }
    return r-l+1;
}

int main(){
    vector<int> vec={1,2,3,3,3,4,4,5,6,7,8,8};
    cout << Count(vec,1) << " ";//1
    cout << Count(vec,2) << " ";//1
    cout << Count(vec,3) << " ";//3
    cout << Count(vec,4) << " ";//2
    cout << Count(vec,5) << " ";//1
    cout << Count(vec,6) << " ";//1
    cout << Count(vec,7) << " ";//1
    cout << Count(vec,8) << " ";//2
    cout << Count(vec,10)<< " ";//0

    return 0;
}
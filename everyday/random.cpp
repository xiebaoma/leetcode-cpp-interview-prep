#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void randomvec(vector<int>& nums){
    random_device rd;
    mt19937 g(rd());
    shuffle(nums.begin(), nums.end(),g);
}

void print(vector<int>& nums){
    for(int i:nums){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums{1,2,3,4,5,6,7,8};
    print(nums);
    randomvec(nums);
    print(nums);
    randomvec(nums);
    print(nums);
    randomvec(nums);
    print(nums);
    randomvec(nums);
    print(nums);
}
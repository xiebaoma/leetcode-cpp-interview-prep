#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// nums = [1, 3, -1, -3, 5, 3, 6, 7]，k = 3

vector<int> maxwindow(vector<int>& vec, int k){
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<vec.size();i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && vec[dq.back()]<vec[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            res.push_back(vec[dq.front()]);
        }
    }
    return res;
}

int main(){
    vector<int> vec({1,3,-1,-3,5,3,6,7});
    vector<int> res=maxwindow(vec, 3);
    for(int i= 0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
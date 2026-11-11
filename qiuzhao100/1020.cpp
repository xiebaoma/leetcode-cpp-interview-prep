#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
//1,8,8

vector<int> strnums(string& s){
    int i=0;
    int j=0;
    int v1=0;
    int v2=0;
    int v3=0;
    while(s[j]!=','){
        v1=v1*10+(s[j]-'0');
        j++;
    }
    //cout << "v1="<<v1<<endl;
    i=j+1;
    j=j+1;
    while(s[j]!=','){
        v2=v2*10+(s[j]-'0');
        j++;
    }
    //cout << "v2="<<v2<<endl;
    i=j+1;
    j=j+1;
    while(j<s.size()){
        v3=v3*10+(s[j]-'0');
        j++;
    }
    //cout << "v3="<<v3<<endl;
    vector<int> res({v1,v2,v3});
    return res;
}

void printvec(vector<int> vec){
    for(int i=0;i< vec.size();i++){
        cout<< vec[i];
    }
}

int main(){
    string s="";
    cin >> s;
    int res=0;
    vector<int> nums= strnums(s);
    //printvec(nums);
    priority_queue<int> pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }
    while(true){
        int v1= pq.top();
        pq.pop();
        if(v1<=0){
            break;
        }
        int v2= pq.top();
        pq.pop();
        if(v2<=0){
            break;
        }
        pq.push(v1-1);
        pq.push(v2-1);
        res+=1;
    }
    cout<< res<<endl;
    return 0;
}
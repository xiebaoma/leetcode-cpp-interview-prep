#include <iostream>
#include <vector>
using namespace std;

void mergearray(vector<int>& numa, vector<int>& numb){
    int n= numb.size();
    if(n==0){
        return;
    }
    int a=n-1;
    int b=n-1;
    for(int i=2*n-1;i>=0;i--){
        if(a<0){
            numa[i]=numb[b];
            b--;
        }else if(b<0){
            numa[i]=numa[a];
            a--;
        }else{
            if(numa[a]>=numb[b]){
                numa[i]=numa[a];
                a--;
            }else{
                numa[i]=numb[b];
                b--;
            }
        }
    }
    return;
}

void print(vector<int>& num){
    for(int i:num){
        cout << i << " ";
    }
    cout << endl;
}


int main(){
    cout << "hello" << endl;
    vector<int> numa(6);
    vector<int> numb(3);
    numa[0]=1;
    numa[1]=3;
    numa[2]=5;
    print(numa);

    numb[0]=2;
    numb[1]=4;
    numb[2]=6;
    print(numb);

    mergearray(numa, numb);
    print(numa);

    return 0;
}


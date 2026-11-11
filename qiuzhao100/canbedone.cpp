#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool dfs(char k, unordered_map<char, vector<char>>& taskmap,vector<int>& isvisit){
    isvisit[k-'a']=1;
    if(taskmap.find(k)==taskmap.end()){
        isvisit[k-'a']=2;
        return true;
    }
    vector<char> next= taskmap[k];
    for(int i=0;i<next.size();i++){
        char nextk=next[i];
        if(isvisit[nextk-'a']==1){
            return false;
        }else if(isvisit[nextk-'a']==2){
            continue;
        }
        if(dfs(nextk, taskmap, isvisit)==false){
            return false;
        }
    }
    isvisit[k-'a']=2;
    return true;
}

bool canbedone(vector<vector<char>>& tasks){
    unordered_map<char, vector<char>> taskmap;
    vector<char> firsttask;
    for(int i=0;i<tasks.size();i++){
        char v= tasks[i][0];
        char k= tasks[i][1];
        if(k==' '){
            firsttask.push_back(v);
        }else{
            taskmap[k].push_back(v);
        }
    }
    for(auto it: taskmap){
        char k= it.first;
        vector<int> isvisit(26, 0);
        if(dfs(k, taskmap, isvisit)==false){
            return false;
        }
    }
    return true;
}


//b->a
//c->b
//c->d
int main(){
    vector<vector<char>> task;
    task.push_back({'a', 'b'});
    task.push_back({'b', 'c'});
    task.push_back({'c', 'a'});
    task.push_back({'d', 'c'});
    if(canbedone(task)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
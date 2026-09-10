#include <unordered_map>
#include <vector>
using namespace std;


class unionfind{
public:
    unordered_map<int,int> parent;

    void unite(vector<int>& pair){
        int i=pair[0];
        int j=pair[1];
        if (parent.find(i) == parent.end()) {
            parent[i] = i;
        }
        if (parent.find(j) == parent.end()) {
            parent[j] = j;
        }

        int rooti= find(i);
        int rootj= find(j);
        
        if(rooti==rootj) return;

        parent[rooti]=rootj;
    }

    int find(int i){
        if(parent[i]!=i){
            parent[i]= find(parent[i]);
        }
        return parent[i];
    }

    vector<vector<int>> getgroup(){
        vector<vector<int>> group;
        unordered_map<int, vector<int>> tmp;
        for(auto it: parent){
            tmp[find(it.first)].push_back(it.first);
        }
        for(auto it: tmp){
            group.push_back(it.second);
        }
        return group;
    }
};

vector<vector<int>> findgroup(vector<vector<int>>& pairs){
    unionfind uf;
    for(int i=0;i<pairs.size();i++){
        uf.unite(pairs[i]);
    }
    return uf.getgroup();
}

int main(){
    vector<vector<int>> pairs;
    pairs.push_back({1,2});
    pairs.push_back({2,3});
    pairs.push_back({4,5});
    pairs.push_back({6,7});
    pairs.push_back({5,6});

    vector<vector<int>> group= findgroup(pairs);

    return 0;
}
/**
 * xiebaoma
 * 2025-10-19
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        double m=0;
        int n=items.size();
        //进行价值密度排序
        sort(items.begin(),items.end(), [](auto &a, auto &b) { return double(a[0])/a[1] > double(b[0])/b[1]; });
        
        for(int i=0;i<n;i++){
            if(items[i][1]<capacity){
                m +=items[i][0];
                capacity -=items[i][1];
            }
            else{
                
                m +=items[i][0]*double(capacity)/items[i][1];
                
                return m;
                break;
            }
        }
        return -1;
    }
};

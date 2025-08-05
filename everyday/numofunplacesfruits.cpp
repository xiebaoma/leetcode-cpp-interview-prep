/**
 * xiebaoma
 * 2025-08-05
 */

#include<vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count =0;
        for(int i = 0; i< n; i++){
            bool enough=false;
            for(int j =0;j<baskets.size();j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j]=0;
                    enough = true;
                    break;
                }
            }
            if(enough){
                count++;
            }
        }
        return n- count;
    }
};
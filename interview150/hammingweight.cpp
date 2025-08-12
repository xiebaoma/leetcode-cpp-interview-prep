/**
 * xiebaoma
 * 2025-08-11
 */

class Solution {
public:
    int hammingWeight(int n) {
        int ret=0;
        while(n>0){
            if(n%2==1){
                ret++;
            }
            n/=2;
        }
        return ret;      
    }
};
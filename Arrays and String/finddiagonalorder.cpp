/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int len = mat.size();
        if(len==1){
            return mat[0];
        }
        int clen = mat[0].size();
        int sum = len*clen;
        vector<int> ret;
        int i=0;
        int j=0;
        bool isup= true;
        int count=0;
        while(count<sum){
            ret.push_back(mat[i][j]);
            count++;
            if(isup){
                if(i==0 && j<clen-1){
                    isup=false;
                    j++;
                }else if(j==clen-1){
                    isup=false;
                    i++;
                }else{
                    i--;
                    j++;
                }
            }else{
                if(j==0 && i<len -1){
                    i++;
                    isup=true;
                }else if(i==len -1){
                    j++;
                    isup= true;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return ret;
    }
};
/**
 * xiebaoma
 * 2025-07-08
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dir = 1; // 1,2,3,4
        int count = 0;
        int sum = m * n;
        vector<int> ret;
        int i=0;
        int j=0;
        while (count < sum)
        {
            count++;
            ret.push_back(matrix[i][j]);
            visited[i][j]=true;
            if(dir==1){
                if(j==n-1 || visited[i][j+1]){
                    dir =2;
                    i++;
                }else{
                    j++;
                }
            }else if(dir==2){
                if(i==m-1 || visited[i+1][j]){
                    dir=3;
                    j--;
                }else{
                    i++;
                }
            }else if(dir==3){
                if(j==0 || visited[i][j-1]){
                    dir =4;
                    i--;
                }else{
                    j--;
                }
            }else{
                if(i==0 || visited[i-1][j]){
                    dir=1;
                    j++;
                }else{
                    i--;
                }
            }
        }
        return ret;
    }
};
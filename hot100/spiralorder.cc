/**
 * xiebaoma
 * 2025-12-14
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> used(n,vector<int>(m));
        vector<int> res;
        int count=1;
        int i=0;
        int j=0;
        int dir=1;
        while (count<=n*m)
        {
            if (dir==1)
            {
                res.push_back(matrix[i][j]);
                used[i][j]=1;
                if (j+1<m && used[i][j+1]==0)
                {
                    j++;
                }else
                {
                    i++;
                    dir=2;
                }
            }else if (dir==2)
            {
                res.push_back(matrix[i][j]);
                used[i][j]=1;
                if (i+1<n && used[i+1][j]==0)
                {
                    i++;
                }else
                {
                    j--;
                    dir=3;
                }
            }else if (dir==3)
            {
                res.push_back(matrix[i][j]);
                used[i][j]=1;
                if (j-1>=0 && used[i][j-1]==0)
                {
                    j--;
                }else
                {
                    i--;
                    dir=4;
                }
            }else if (dir==4)
            {
                res.push_back(matrix[i][j]);
                used[i][j]=1;
                if (i-1>=0 && used[i-1][j]==0)
                {
                    i--;
                }else
                {
                    j++;
                    dir=1;
                }
            }
            count++;
        }
        return res;
    }
};
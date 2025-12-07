/**
 * xiebaoma
 * 2025-12-07
 */
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        for (int i =0;i<matrix.size();i++)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                if (matrix[i][j]==0)
                {
                    row.emplace(i);
                    col.emplace(j);
                }
            }
        }
        for (int i:row)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                matrix[i][j]=0;
            }
        }
        for (int j:col)
        {
            for (int i=0;i<matrix.size();i++)
            {
                matrix[i][j]=0;
            }
        }
        return;
    }
};
/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> row;
        vector<int> clo;
        int rlen = matrix.size();
        int clen = matrix[0].size();
        for (int i = 0; i < rlen; i++)
        {
            for (int j = 0; j < clen; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.push_back(i);
                    clo.push_back(j);
                }
            }
        }
        for (int i : row)
        {
            for (int j = 0; j < clen; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for (int j : clo)
        {
            for (int i = 0; i < rlen; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};
/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len / 2; j++)
            {
                swap(matrix[i][j], matrix[i][len - j - 1]);
            }
        }
        for (int i = 0; i < len-1; i++)
        {
            for (int j = 0; j < len - i - 1; j++)
            {
                swap(matrix[i][j], matrix[len-j-1][len-i-1]);
            }
        }
    }
};
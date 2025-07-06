/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int numRows)
    {
        vector<vector<int>> ret;
        if (numRows == 0)
        {
            vector<int> row{1};
            return row;
        }
        if (numRows == 1)
        {

            vector<int> row2{1, 1};
            return row2;
        }
        vector<int> row{1};
        vector<int> row2{1, 1};
        ret.push_back(row);
        ret.push_back(row2);
        for (int i = 3; i <= numRows+1; i++)
        {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i - 1; j++)
            {
                row.push_back(ret[i - 2][j - 1] + ret[i - 2][j]);
            }
            row.push_back(1);
            ret.push_back(row);
        }
        return ret[numRows];
    }
};
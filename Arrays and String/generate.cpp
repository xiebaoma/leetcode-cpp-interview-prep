/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;
        if (numRows == 1)
        {
            vector<int> row{1};
            ret.push_back(row);
            return ret;
        }
        if (numRows == 2)
        {
            vector<int> row{1};
            vector<int> row2{1, 1};
            ret.push_back(row);
            ret.push_back(row2);
            return ret;
        }
        vector<int> row{1};
        vector<int> row2{1, 1};
        ret.push_back(row);
        ret.push_back(row2);
        for (int i = 3; i <= numRows; i++)
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
        return ret;
    }
};
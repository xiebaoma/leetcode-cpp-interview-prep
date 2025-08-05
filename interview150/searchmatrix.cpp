/**
 * xiebaoma
 * 2025-08-04
 */

#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int up = 0;
        int down = matrix.size() - 1;
        int mid = up + (down - up) / 2;
        while (up <= down)
        {
            if (matrix[mid][0] == target)
            {
                return true;
            }
            if (matrix[mid][0] > target)
            {
                down = mid - 1;
            }
            else
            {
                up = mid + 1;
            }
            mid = up + (down - up) / 2;
        }
        if (up == 0)
        {
            row = 0;
        }
        else
        {
            row = up - 1;
        }

        int left = 0;
        int right = matrix[row].size() - 1;
        mid = left + (right - left) / 2;
        while (left <= right)
        {
            if (matrix[row][mid] == target)
            {
                return true;
            }
            if (matrix[row][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
        }
        return false;
    }
};
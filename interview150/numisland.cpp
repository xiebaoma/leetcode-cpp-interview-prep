/**
 * xiebaoma
 * 2025-07-26
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int m = grid.size();
        int n = grid[0].size();
        grid[r][c] = 0;

        if (r - 1 >= 0 && grid[r - 1][c] == '1')
            dfs(grid, r - 1, c);
        if (r + 1 < m && grid[r + 1][c] == '1')
            dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
            dfs(grid, r, c - 1);
        if (c + 1 < n && grid[r][c + 1] == '1')
            dfs(grid, r, c + 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int m = grid.size();
        if (!m)
            return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
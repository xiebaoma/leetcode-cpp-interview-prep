/**
 * xiebaoma
 * 2025-07-08
 */

#include <vector>
using namespace std;

class Solution
{
public:
    bool checklive(vector<vector<int>> &board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        int livecount = 0;
        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
            livecount++;
        if (i - 1 >= 0 && board[i - 1][j] == 1)
            livecount++;
        if (i - 1 >= 0 && j + 1 <= n - 1 && board[i - 1][j + 1])
            livecount++;
        if (j - 1 >= 0 && board[i][j - 1] == 1)
            livecount++;
        if (j + 1 <= n - 1 && board[i][j + 1] == 1)
            livecount++;
        if (i + 1 <= m - 1 && j - 1 >= 0 && board[i + 1][j - 1] == 1)
            livecount++;
        if (i + 1 <= m - 1 && board[i + 1][j] == 1)
            livecount++;
        if (i + 1 <= m - 1 && j + 1 <= n - 1 && board[i + 1][j + 1] == 1)
            livecount++;
        if (board[i][j] == 1)
        {
            if (livecount < 2 || livecount > 3)
                return false;
        }
        else
        {
            if (livecount != 3)
                return false;
        }
        return true;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (checklive(board, i, j))
                {
                    ret[i][j] = 1;
                }
                else
                {
                    ret[i][j] = 0;
                }
            }
        }
        board = ret;
    }
};
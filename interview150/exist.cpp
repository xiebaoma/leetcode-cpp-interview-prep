/**
 * xiebaoma
 * 2025-08-02
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool valid;
    void dfs(vector<vector<char>> &board, int x, int y, string &word, int index)
    {
        int n = word.size();
        int row = board.size();
        int col = board[0].size();
        if (board[x][y] == word[index] && index == n - 1)
        {
            valid = true;
            return;
        }
        if (board[x][y] != word[index])
        {
            return;
        }
        char c = board[x][y];
        board[x][y] = '#';
        if (x - 1 >= 0 && board[x - 1][y] != '#')
            dfs(board, x - 1, y, word, index + 1);
        if (x + 1 < row && board[x + 1][y] != '#')
            dfs(board, x + 1, y, word, index + 1);
        if (y - 1 >= 0 && board[x][y - 1] != '#')
            dfs(board, x, y - 1, word, index + 1);
        if (y + 1 < col && board[x][y + 1] != '#')
            dfs(board, x, y + 1, word, index + 1);
        board[x][y] = c;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        valid = false;

        int row = board.size();
        int col = board[0].size();
        for (int x = 0; x < row; x++)
        {
            for (int y = 0; y < col; y++)
            {
                dfs(board, x, y, word, 0);
                if (valid)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
/**
 * xiebaoma
 * 2025-08-31
 */

#include <vector>
using namespace std;

class Solution
{
public:
    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] != '.')
                    continue;
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(board, i, j, ch))
                    {
                        board[i][j] = ch;
                        if (backtracking(board))
                            return true;
                    }
                }
                board[i][j] = '.';
                return false;
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char val)
    {
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == val)
                return false;
            if (board[row][i] == val)
                return false;
            if (board[startRow + i / 3][startCol + i % 3] == val)
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};
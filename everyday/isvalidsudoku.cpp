/**
 * xiebaoma
 * 2025-08-30
 */

#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<char> mset1;
        set<char> mset2;
        set<char> mset3;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mset1.find(board[i][j]) != mset1.end() && board[i][j] != '.')
                {
                    return false;
                }
                else
                {
                    mset1.emplace(board[i][j]);
                }

                if (mset2.find(board[j][i]) != mset2.end() && board[j][i] != '.')
                {
                    return false;
                }
                else
                {
                    mset2.emplace(board[j][i]);
                }
            }
            mset1.clear();
            mset2.clear();
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                for (int i1 = i; i1 < i + 3; i1++)
                {
                    for (int j1 = j; j1 < j + 3; j1++)
                    {
                        if (mset3.find(board[i1][j1]) != mset3.end() && board[i1][j1] != '.')
                        {
                            return false;
                        }
                        else
                        {
                            mset3.emplace(board[i1][j1]);
                        }
                    }
                }
                mset3.clear();
            }
        }
        return true;
    }
};
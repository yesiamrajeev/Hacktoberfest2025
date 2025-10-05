#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> leftRow(n, false);
        vector<bool> upperDiagonal(2 * n - 1, false);
        vector<bool> lowerDiagonal(2 * n - 1, false);
        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n,
               vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (!leftRow[col] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 + col - row])
            {
                board[row][col] = 'Q';
                leftRow[col] = true;
                lowerDiagonal[row + col] = true;
                upperDiagonal[n - 1 + col - row] = true;

                solve(row + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = '.';
                leftRow[col] = false;
                lowerDiagonal[row + col] = false;
                upperDiagonal[n - 1 + col - row] = false;
            }
        }
    }
};
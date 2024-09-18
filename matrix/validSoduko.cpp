#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            // We create a new set for each line!
            set<char> sudokuRowSet;
            set<char> sudokuColSet;

            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (sudokuRowSet.find(board[i][j]) != sudokuRowSet.end())
                    {
                        return false; // The same number was found.
                    }
                    sudokuRowSet.insert(board[i][j]);
                }

                if (board[j][i] != '.')
                {
                    if (sudokuColSet.find(board[j][i]) != sudokuColSet.end())
                    {
                        return false; // The same number was found.
                    }
                    sudokuColSet.insert(board[j][i]);
                }
            }
        }

        // Get ready a lot of for loops...
        // The following 2 for loops are to create the basic 3x3 matrix of each sudoku box
        for (int boxRow = 0; boxRow < 9; boxRow += 3)
        {
            for (int boxCol = 0; boxCol < 9; boxCol += 3)
            {
                // These 2 for loops are to check each value inside each box.
                set<char> sudokuBoxSet;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i + boxRow][j + boxCol] != '.')
                        {
                            if (sudokuBoxSet.find(board[i + boxRow][j + boxCol]) != sudokuBoxSet.end())
                            {
                                return false;
                            }
                            sudokuBoxSet.insert(board[i + boxRow][j + boxCol]);
                        }
                    }
                }
            }
        }

        return true;
    }
};
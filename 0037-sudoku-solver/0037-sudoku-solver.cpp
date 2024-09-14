#include <vector>
using namespace std;

class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }


    bool solve(vector<vector<char>>& board) {
        // Traverse each cell on the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
               
                if (board[i][j] == '.') {
                    // Try numbers '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {
                        // Check if placing 'c' in the current cell is valid
                        if (isvalid(board, c, i, j)) {
                            board[i][j] = c;  // Place the valid number

                            // If placing the number leads to a solution, return true
                            if (solve(board)) {
                                return true;
                            } else {
                                // If not, backtrack by resetting the cell
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If no valid number can be placed, return false
                    return false;
                }
            }
        }
        // If all cells are filled correctly, return true
        return true;
    }
    bool isvalid(vector<vector<char>>& board, char c, int row, int col) {
    
        for (int i = 0; i < 9; i++) {

            if (board[row][i] == c) return false;

            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};

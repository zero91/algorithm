// Problem:
//
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// Empty cells are indicated by the character '.'.
//
// You may assume that there will be only one unique solution.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int remain[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                remain[i][j] = (1 << 9) - 1;
            }
        }

        int pos = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                remain[i][j] = 0;
                pos = 1 << (board[i][j] - '1');
                for (int k = 0; k < 9; ++k) {
                    remain[i][k] &= ~pos;
                    remain[k][j] &= ~pos;
                    remain[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] &= ~pos;
                }
            }
        }
        search(0, 0, board, remain);
    }

private:
    bool search(int row, int col, vector<vector<char>>& board, int remain[9][9]) {
        if (row == 9) return true;
        if (col == 9) return search(row + 1, 0, board, remain);
        if (board[row][col] != '.') return search(row, col + 1, board, remain);

        int save[9][9];
        for (int k = 0; k < 9; ++k) {
            if ((remain[row][col] & (1 << k)) == 0) {
                continue;
            }

            memmove(save, remain, sizeof(save));
            board[row][col] = '1' + k;
            for (int i = 0; i < 9; ++i) {
                save[row][i] &= ~(1 << k);
                save[i][col] &= ~(1 << k);
                save[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] &= ~(1 << k);
            }

            if (search(row, col + 1, board, save)) return true;
            board[row][col] = '.';
        }
        return false;
    }
};

int main() {
    char b[9][10] = { "53..7....",
                      "6..195...",
                      ".98....6.",
                      "8...6...3",
                      "4..8.3..1",
                      "7...2...6",
                      ".6....28.",
                      "...419..5",
                      "....8..79" };

    vector<vector<char>> board;
    for (int i = 0; i < 9; ++i) {
        vector<char> v;
        for (int j = 0; j < 9; ++j) {
            v.push_back(b[i][j]);
        }
        board.push_back(v);
    }
    
    Solution sol;
    sol.solveSudoku(board);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

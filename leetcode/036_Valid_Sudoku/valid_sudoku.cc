// Problem:
//
// Determine if a Sudoku is valid.
//
// The Sudoku board could be partially filled,
// where empty cells are filled with the character '.'.
//
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable.
// Only the filled cells need to be validated.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int h[9][9], v[9][9], s[9][9];
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        memset(s, 0, sizeof(s));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (h[i][ch - '1']++ > 0) return false;
                if (v[j][ch - '1']++ > 0) return false;
                if (s[i / 3 * 3 + j / 3][ch - '1']++ > 0) return false;
            }
        }
        return true;
    }
};

int main() {
    //vector<vector<char>> board;

    char b[9][10] = {".87654321",
                     "2........",
                     "3........",
                     "4........",
                     "5........",
                     "6........",
                     "7........",
                     "8........",
                     "9........"};
    vector<vector<char>> board;

    for (int i = 0; i < 9; ++i) {
        vector<char> v;
        for (int j = 0; j < 9; ++j) {
            v.push_back(b[i][j]);
        }
        board.push_back(v);
    }
    
    Solution sol;
    cout << sol.isValidSudoku(board) << endl;

    return 0;
}

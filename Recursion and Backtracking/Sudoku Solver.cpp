#include <bits/stdc++.h>
using namespace std;

class Sudoku {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board);
    }

    bool sudokuSolver(vector<vector<char>>& board) {
        int n = board.size();
        int r = -1;
        int c = -1;
        bool check = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    r = i;
                    c = j;
                    check = false;
                    break;
                }
            }
            if (check == false) break;
        }
        if (check == true) return true;

        for (int k = 1; k <= 9; k++) {
            if (isSafe(board, r, c, k)) {
                board[r][c] = (char)(k + '0');
                if (sudokuSolver(board)) return true;
                else board[r][c] = '.';
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, int index) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == (char)(index + '0')) return false;
        }
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == (char)(index + '0')) return false;
        }
        int sqrtv = (int)sqrt(board.size());
        int rowlim = row - row % sqrtv;
        int collim = col - col % sqrtv;
        for (int i = rowlim; i < rowlim + sqrtv; i++) {
            for (int j = collim; j < collim + sqrtv; j++) {
                if (board[i][j] == (char)(index + '0')) return false;
            }
        }
        return true;
    }
};

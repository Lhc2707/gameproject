#ifndef _LOGIC__H
#define _LOGIC__H

#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;

    void init() {
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
    }
    void move(int row, int column) {
        if (row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE)
        {
            board[row][column] = nextMove;
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
        }
    }

    bool checkWin(char player) {
        // Kiểm tra hàng
        for (int i = 0; i < BOARD_SIZE; ++i) {
            bool win = true;
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // Kiểm tra cột
        for (int j = 0; j < BOARD_SIZE; ++j) {
            bool win = true;
            for (int i = 0; i < BOARD_SIZE; ++i) {
                if (board[i][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // Kiểm tra đường chéo chính
        bool win = true;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][i] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;

        // Kiểm tra đường chéo phụ
        win = true;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][BOARD_SIZE - 1 - i] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;

        return false;
    }

    // Kiểm tra hòa (tất cả ô đều đầy và không ai thắng)
    bool isDraw() {
        for (int i = 0; i < BOARD_SIZE; ++i)
            for (int j = 0; j < BOARD_SIZE; ++j)
                if (board[i][j] == EMPTY_CELL)
                    return false;
        return !checkWin(O_CELL) && !checkWin(X_CELL);
    }
};

#endif

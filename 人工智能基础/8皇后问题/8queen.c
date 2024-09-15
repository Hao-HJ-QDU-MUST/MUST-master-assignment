#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8  // 定义棋盘的大小

int board[N][N];  // 定义8×8的棋盘

// 打印棋盘的函数
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 检查能否在棋盘的某一行某一列放置皇后
bool isSafe(int row, int col) {
    int i, j;

    // 检查当前列是否有其他皇后
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // 检查左上方对角线是否有皇后
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // 检查右上方对角线是否有皇后
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// 使用回溯法解决问题
bool solveNQueens(int row) {
    // 如果所有皇后都放置好了，返回true
    if (row >= N) {
        printSolution();
        return true;
    }

    bool res = false; // 记录是否找到解

    // 尝试在当前行的每一列放置皇后
    for (int i = 0; i < N; i++) {
        if (isSafe(row, i)) {
            // 放置皇后
            board[row][i] = 1;

            // 递归尝试放置下一行的皇后
            res = solveNQueens(row + 1) || res;

            // 回溯：移除皇后
            board[row][i] = 0;
        }
    }

    return res;
}

int main() {
    // 初始化棋盘
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // 解决8皇后问题
    if (!solveNQueens(0)) {
        printf("没有找到解决方案\n");
    }

    return 0;
}

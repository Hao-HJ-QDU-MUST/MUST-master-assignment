#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8  // �������̵Ĵ�С

int board[N][N];  // ����8��8������

// ��ӡ���̵ĺ���
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ����ܷ������̵�ĳһ��ĳһ�з��ûʺ�
bool isSafe(int row, int col) {
    int i, j;

    // ��鵱ǰ���Ƿ��������ʺ�
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // ������Ϸ��Խ����Ƿ��лʺ�
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // ������Ϸ��Խ����Ƿ��лʺ�
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// ʹ�û��ݷ��������
bool solveNQueens(int row) {
    // ������лʺ󶼷��ú��ˣ�����true
    if (row >= N) {
        printSolution();
        return true;
    }

    bool res = false; // ��¼�Ƿ��ҵ���

    // �����ڵ�ǰ�е�ÿһ�з��ûʺ�
    for (int i = 0; i < N; i++) {
        if (isSafe(row, i)) {
            // ���ûʺ�
            board[row][i] = 1;

            // �ݹ鳢�Է�����һ�еĻʺ�
            res = solveNQueens(row + 1) || res;

            // ���ݣ��Ƴ��ʺ�
            board[row][i] = 0;
        }
    }

    return res;
}

int main() {
    // ��ʼ������
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // ���8�ʺ�����
    if (!solveNQueens(0)) {
        printf("û���ҵ��������\n");
    }

    return 0;
}

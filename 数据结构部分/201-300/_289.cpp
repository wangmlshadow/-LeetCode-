#include "normal.h"

/*
���� �ٶȰٿ� ��������Ϸ�����Ϊ��������Ӣ����ѧ��Լ�����ζ١������� 1970 �귢����ϸ���Զ�����

����һ������ m �� n �����ӵ���壬ÿһ�����Ӷ����Կ�����һ��ϸ����ÿ��ϸ��������һ����ʼ״̬��1 ��Ϊ
��ϸ����live������ 0 ��Ϊ��ϸ����dead����ÿ��ϸ������˸�����λ�ã�ˮƽ����ֱ���Խ��ߣ���ϸ������ѭ
�����������涨�ɣ�

�����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������
�����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��
�����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������
�����ϸ����Χ������������ϸ�������λ����ϸ�����
���ݵ�ǰ״̬��дһ���������������������ϸ������һ����һ�θ��º�ģ�״̬����һ��״̬��ͨ������������
ͬʱӦ���ڵ�ǰ״̬�µ�ÿ��ϸ�����γɵģ�����ϸ���ĳ�����������ͬʱ�����ġ�
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        cols = rows == 0 ? 0 : board[0].size();

        if (rows == 0 || cols == 0)
            return;

        // 2��ʾ ��������
        // 3��ʾ �ӻ��

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int n = getLife(i, j, board);

                if (board[i][j] == 0) {
                    if (n == 3)
                        board[i][j] = 2;
                }
                else {
                    if (n < 2 || n > 3)
                        board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;

                if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
private:
    int rows;
    int cols;

    int getLife(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;

        if (row - 1 >= 0 && col - 1 >= 0)
            if (board[row - 1][col - 1] == 1 || board[row - 1][col - 1] == 3)
                cnt++;

        if (row - 1 >= 0)
            if (board[row - 1][col] == 1 || board[row - 1][col] == 3)
                cnt++;

        if (row - 1 >= 0 && col + 1 < cols)
            if (board[row - 1][col + 1] == 1 || board[row - 1][col + 1] == 3)
                cnt++;

        if (col - 1 >= 0)
            if (board[row][col - 1] == 1 || board[row][col - 1] == 3)
            cnt++;

        if (col + 1 < cols)
            if (board[row][col + 1] == 1 || board[row][col + 1] == 3)
                cnt++;

        if (row + 1 < rows && col - 1 >= 0)
            if (board[row + 1][col - 1] == 1 || board[row + 1][col - 1] == 3)
                cnt++;

        if (row + 1 < rows)
            if (board[row + 1][col] == 1 || board[row + 1][col] == 3)
                cnt++;

        if (row + 1 < rows && col + 1 < cols)
            if (board[row + 1][col + 1] == 1 || board[row + 1][col + 1] == 3)
                cnt++;

        return cnt;
    }
}; 
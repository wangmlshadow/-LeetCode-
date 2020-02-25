#include "normal.h"

/*
�ж�һ�� 9x9 �������Ƿ���Ч��ֻ��Ҫ�������¹�����֤�Ѿ�����������Ƿ���Ч���ɡ�
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {      
        vector<vector<int>> row(9, vector<int>(9, 0));   // ��
        vector<vector<int>> col(9, vector<int>(9, 0));   // ��
        vector<vector<int>> box(9, vector<int>(9, 0));   // �ֿ�

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int cur = board[i][j] - '0' -1;
                int box_i = (i / 3) * 3 + j / 3;

                row[i][cur]++;
                col[j][cur]++;
                box[box_i][cur]++;

                if (row[i][cur] > 1 || col[j][cur] > 1 || box[box_i][cur] > 1)
                    return false;
            }
        }

        return true;
    }
};
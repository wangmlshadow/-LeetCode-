#include "normal.h"

/*

����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά���񣬼��㵺���������һ������ˮ
��Χ����������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�����Լ����������
���߾���ˮ��Χ��
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();

        if (row == 0)
            return 0;

        int col = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    to2(i, j, grid);
                }
            }
        }

        return cnt;
    }

    void to2(int row, int col, vector<vector<char>>& grid) {   // �����ظ� ���Ѿ����ʹ���½�ر�Ϊ2
        if (grid[row][col] == '0' || grid[row][col] == '2')
            return;

        grid[row][col] = '2';

        if (row > 0)
            to2(row - 1, col, grid);

        if (row < grid.size() - 1)
            to2(row + 1, col, grid);

        if (col > 0)
            to2(row, col - 1, grid);

        if (col < grid[0].size() - 1)
            to2(row, col + 1, grid);
    }
};
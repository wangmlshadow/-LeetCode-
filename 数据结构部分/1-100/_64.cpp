#include "normal.h"

/*
����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��

˵����ÿ��ֻ�����»��������ƶ�һ����
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> minPath(row, vector<int>(col, 0));
        minPath[0][0] = grid[0][0];

        for (int i = 1; i < col; i++) {
            minPath[0][i] = minPath[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < row; i++) {
            minPath[i][0] = minPath[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                minPath[i][j] = (minPath[i][j - 1] < minPath[i - 1][j]) ? (minPath[i][j - 1] + grid[i][j]) : (minPath[i - 1][j] + grid[i][j]);
            }
        }

        return minPath[row - 1][col - 1];
    }
};
#include "normal.h"


/*
����

����һ�� m * n �ľ��� grid�������е�Ԫ�������ǰ��л��ǰ��У����Էǵ���˳�����С�

����ͳ�Ʋ����� grid �� ���� ����Ŀ��

˼·����gridÿһ�������ֲ�����Ѱ��ÿһ�и�������ʼλ��
*/


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows == 0 ? 0 : grid[0].size();

        if (rows * cols == 0 || grid[rows - 1][cols - 1] >= 0)
            return 0;

        int res = 0, left, right;
        // ÿһ����һ������
        for (int row = 0; row < rows; row++) {
            left = 0;
            right = cols - 1;
            while (left <= right) {
                int mid = (left + right) / 2;

                if (grid[row][mid] >= 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            res += (cols - left);
        }

        return res;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��16 ms, ������ C++ �ύ�л�����87.16%���û�
�ڴ����ģ�7.9 MB, ������ C++ �ύ�л�����100.00%���û�
*/
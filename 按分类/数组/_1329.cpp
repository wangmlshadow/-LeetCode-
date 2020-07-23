#include "normal.h"

/*
����

����һ�� m * n ���������� mat �����㽫ͬһ���Խ����ϵ�Ԫ�أ������ϵ����£�����������󣬷����ź���ľ���

˼·��һ�����Խ��߽������� ���¸�ֵ
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = rows == 0 ? 0 : mat[0].size();

        if (rows * cols == 0 || rows == 1 || cols == 1)
            return mat;

        //vector<vector<int>> res(mat);

        // �Խ�����ʼ��� [0][0] -> [rows - 2][0]
        for (int i = 0; i < rows - 1; i++) {
            vector<int> temp;
            for (int row = i, col = 0; row < rows && col < cols; row++, col++) {
                temp.push_back(mat[row][col]);
            }

            sort(temp.begin(), temp.end());

            for (int row = i, col = 0, j = 0; row < rows && col < cols; row++, col++, j++) {
                mat[row][col] = temp[j];
            }
        }

        // �Խ�����ʼ���[0][cols - 2] -> [0][1]
        for (int i = cols - 2; i > 0; i--) {
            vector<int> temp;
            for (int row = 0, col = i; row < rows && col < cols; row++, col++) {
                temp.push_back(mat[row][col]);
            }

            sort(temp.begin(), temp.end());

            for (int row = 0, col = i, j = 0; row < rows && col < cols; row++, col++, j++) {
                mat[row][col] = temp[j];
            }
        }

        return mat;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��28 ms, ������ C++ �ύ�л�����50.44%���û�
�ڴ����ģ�9 MB, ������ C++ �ύ�л�����100.00%���û�
*/
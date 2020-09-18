#include "normal.h"

/*
����

����һ������ A�� ���� A ��ת�þ���

�����ת����ָ����������Խ��߷�ת���������������������������

˼·��i,j -> j,i
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = rows == 0 ? 0 : A[0].size();

        if (rows * cols == 0)
            return A;

        vector<vector<int>> res(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[j][i] = A[i][j];
            }
        }

        return res;
    }
};

/*
ִ�н����ͨ����ʾ����
ִ����ʱ��24 ms, ������ C++ �ύ�л�����34.24%���û�
�ڴ����ģ�9.8 MB, ������ C++ �ύ�л�����71.24%���û�
*/
#include "normal.h"

/*
����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int l1 = 0, r1 = 0;
        int l2 = n - 1, r2 = n - 1;
        int num = 1;

        while (l1 <= l2 && r1 <= r2) {
            for (int i = r1; i <= r2; i++)
                result[l1][i] = num++;

            for (int i = l1 + 1; i <= l2; i++)
                result[i][r2] = num++;

            if (l1 < l2 && r1 < r2) {
                for (int i = r2 - 1; i >= l1; i--)
                    result[l2][i] = num++;

                for (int i = l2 - 1; i > l1; i--)
                    result[i][r1] = num++;
            }
            
            l1++;
            r1++;
            l2--;
            r2--;
        }

        return result;
    }
};
#include "normal.h"

/*
����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {   // ��ʱ�ʼ�дӵ�0�п�ʼ
        vector<int> res;

        res.push_back(1);
        rowIndex++;
        for (int i = 1; i < rowIndex; i++) {
            vector<int> temp;

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(res[j - 1] + res[j]);
                }
            }

            res = temp;
        }

        return res;
    }
};  // �����ٶȺͿռ�ʹ�ö�����100%
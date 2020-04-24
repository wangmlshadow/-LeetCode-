#include "normal.h"

/*
���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ
����ɺ͵���ȫƽ�����ĸ������١�
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, INT_MAX);
        res[0] = 0;
        int maxSq = sqrt(n) + 1;
        vector<int> sq(maxSq);

        for (int i = 1; i < maxSq; i++)
            sq[i] = i * i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < maxSq; j++) {
                if (i < sq[j])
                    break;

                res[i] = min(res[i], res[i - sq[j]] + 1);
            }
        }

        return res[n];
    }
};
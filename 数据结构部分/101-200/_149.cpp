#include "normal.h"

/*
����һ����άƽ�棬ƽ������ n ���㣬������ж��ٸ�����ͬһ��ֱ���ϡ�
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();

        if (size <= 2)
            return size;

        // ����ȷ��һ��ֱ��
        vector<vector<bool>> sign(size, vector<bool>(size, false));  // ��ʶ���������ֱ���Ѿ�������ˣ������ظ�����
        int i = 1;

        for (; i < size; i++) {
            if (points[i][0] != points[0][0] || points[i][1] != points[1][1])
                break;
        }

        if (i == size)
            return size;

        int max = 2;

        for (i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (sign[i][j])
                    continue;

                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    continue;

                int cnt = 2;
                long long x = points[i][0] * 1.0;
                long long y = points[i][1] * 1.0;
                long long x1 = points[j][0] * 1.0;
                long long y1 = points[j][1] * 1.0;
                // y - y1 / x - x1 = y2 - y1 / x2 - x1��ʾһ��ֱ��
                for (int k = 0; k < size; k++) {
                    if (k == i || k == j)
                        continue;

                    long long x2 = points[k][0] * 1.0;
                    long long y2 = points[k][1] * 1.0;

                    if ((x2 == x && y2 == y) || (x2 == x1 && y2 == y1)) {
                        cnt++;
                        sign[i][k] = true;
                        sign[k][i] = true;
                        sign[j][k] = true;
                        sign[k][j] = true;
                        continue;
                    }

                    if (((y - y1) * (x2 - x1)) == ((y2 - y1) * (x - x1))) {   // ����ʱ������ ����ֱ���������ʽ�ж�
                        cnt++;
                        sign[i][k] = true;
                        sign[k][i] = true;
                        sign[j][k] = true;
                        sign[k][j] = true;
                    }
                }
                
                if (max < cnt)
                    max = cnt;
            }
        }

        return max;
    }
};
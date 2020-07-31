#include "normal.h"

/*
��̬�滮

����һ�������� 0 �� 1 ��ɵĶ�ά���� grid�������ҳ��߽�ȫ���� 1 ��ɵ���� ������ ����
�񣬲����ظ��������е�Ԫ����������������ڣ��򷵻� 0��

˼·�����α������飬Ѱ�ҽ���i,j ��Ϊ�����ε����ϽǶ��㣬������������������
      ע�����������Ϊ�˼��ټ�������������Ż�
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows == 0 ? 0 : grid[0].size();

        if (rows * cols == 0)
            return 0;

        int res = 0;   // ��¼�����α߳�

        for (int i = 0; i < rows - res; i++) {
            for (int j = 0; j < cols - res; j++) {
                if (grid[i][j] == 0)
                    continue;

                res = max(res, 1);
                int maxCnt = 1;

                while (i + maxCnt < rows && j + maxCnt < cols && grid[i + maxCnt][j] == 1 && grid[i][j + maxCnt] == 1)
                    maxCnt++;

                if (res >= maxCnt)  // ���ٲ���Ҫ������
                    continue;

                int cnt = 1;
                

                while (cnt < maxCnt) {
                    bool end = true;   // �����Ƿ񻹿�����ɷ���������������
                    // �У���
                    for (int col = j + 1; col <= j + cnt; col++) {
                        if (grid[i + cnt][col] == 0) {
                            end = false;
                            break;
                        }
                    }

                    for (int row = i + 1; row <= i + cnt; row++) {
                        if (grid[row][j + cnt] == 0) {
                            end = false;
                            break;
                        }
                    }

                    if (end)
                        res = max(res, cnt + 1);

                    cnt++;
                }
            }
        }

        return res * res;
    }
};


/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��32 ms, ������ C++ �ύ�л�����68.27%���û�
�ڴ����ģ�10 MB, ������ C++ �ύ�л�����95.12%���û�
*/

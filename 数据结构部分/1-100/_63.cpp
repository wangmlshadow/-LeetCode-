#include "normal.h"

/*

һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������

���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����

�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<long>> dp(n, vector<long>(m, 0));     // int�ڲ���������̫С�ˡ�����������

        if (obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for (int i = 1; i < m; i++) {
            dp[0][i] = (dp[0][i - 1] == 1 && obstacleGrid[0][i] == 0) ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }

        return dp[n - 1][m - 1];
    }
};
#include "normal.h"

/*
��̬�滮

����һ����ʾ�����ķǸ��������顣 ��� 1 ����������һ����ȡһ�������������� 2 ������ʣ������
����һ����ȡ������Ȼ����� 1 �ã����� ��ÿ��һ�����ֻ����ȡһ����������������ȡ֮���ٿ�ȡ��
ֱ��û��ʣ�������ȡʱ��Ϸ���������ջ�÷����ܺ�������һ�ʤ��

����һ����ʾ���������飬Ԥ�����1�Ƿ���ΪӮ�ҡ�����Լ���ÿ����ҵ��淨����ʹ���ķ�����󻯡�

����˼·��Python�汾
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = 0; i < n; i++)
            dp[i][i][0] = nums[i];

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = l + i - 1;
                int left = nums[i] + dp[i + 1][j][1];
                int right = nums[j] + dp[i][j - 1][1];

                if (left > right) {
                    dp[i][j][0] = left;
                    dp[i][j][1] = dp[i + 1][j][0];
                }
                else {
                    dp[i][j][0] = right;
                    dp[i][j][1] = dp[i][j - 1][0];
                }
            }
        }

        return dp[0][n - 1][0] >= dp[0][n - 1][1];
    }
};
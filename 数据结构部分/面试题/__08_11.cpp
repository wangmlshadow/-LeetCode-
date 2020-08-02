#include "normal.h"

/*
��̬�滮

Ӳ�ҡ������������޵�Ӳ�ң���ֵΪ25�֡�10�֡�5�ֺ�1�֣���д�������n���м�
�ֱ�ʾ����(������ܻ�ܴ�����Ҫ�����ģ��1000000007)
*/

class Solution {
public:
    int waysToChange(int n) { 
        const int mod = 1000000007;
        vector<int> dp(n + 1, 0);
        vector<int> coins = {25, 10, 5, 1};
        dp[0] = 1;

        for (int i = 0; i < 4; i++) {
            int coin = coins[i];

            for (int j = coin; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - coin]) % mod;
            }
        }

        return dp[n];
    }
};

#include "normal.h"

/*

����һ�����飬���ĵ� i ��Ԫ����һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�

���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ס�

ע��: �㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {   // ���в��ɹ� û���㹻�ڴ���� Ӧ����k��ԭ��
        int cnt = prices.size();

        if (cnt < 2)
            return 0;

        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < cnt; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);   // ��Ʊ���״�������������
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        } 

        return dp[cnt - 1][k][0];
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) { // �������ڳ�ʱ��
        int cnt = prices.size();

        if (cnt < 2)
            return 0;

        if (k > cnt / 2)
            k = cnt / 2;   

        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < cnt; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);   // ��Ʊ���״�������������
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[cnt - 1][k][0];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int cnt = prices.size();

        if (cnt < 2)
            return 0;

        if (k > cnt / 2) {
            int res = 0;

            for (int i = 0; i < cnt - 1; i++)
                if (prices[i + 1] > prices[i])
                    res += prices[i + 1] - prices[i];

            return res;
        }
        

        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = 0; i < cnt; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);   // ��Ʊ���״�������������
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[cnt - 1][k][0];
    }
};
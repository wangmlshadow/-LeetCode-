#include "normal.h"

/*
��̬�滮

�г̳��ȱ��� ��һ�ֳ��õ��ַ���ѹ��������������������ͬ�ַ����ظ� 2 �λ����Σ��滻Ϊ�ַ���
��ʾ�ַ����������֣��г̳��ȣ������磬�ô˷���ѹ���ַ��� "aabccc" ���� "aa" �滻Ϊ "a2" ��"ccc" ��
��Ϊ` "c3" �����ѹ������ַ�����Ϊ "a2bc3" ��

ע�⣬�������У�ѹ��ʱû���ڵ����ַ��󸽼Ӽ��� '1' ��

����һ���ַ��� s ��һ������ k ������Ҫ���ַ��� s ��ɾ����� k ���ַ�����ʹ s ���г̳��ȱ��볤����С��

���㷵��ɾ����� k ���ַ���s �г̳��ȱ������С���� ��

˼·��
dp[i][j]��ʾ��ǰi���ַ������ѡ��j���ַ�����ɾ����
���ɾ���ַ�i�����ʱdp[i][j] = dp[i-1][j-1].
��������ַ�i, ���ʱ��������ѡ�������ַ�i��ͬ���ַ������dpȷʵ������⣬������ϸ˼��һ�£����Ž�Ӧ���ǰ���������ġ�

*/

class Solution {  // ���
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if (k >= s.length())
            return 0;

        vector<vector<int>> dp(s.length() + 1, vector<int>(k + 2, 0x3f3f3f3f));
        dp[0][0] = 0;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j <= k && j <= i; j++) {
                if (j < k)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);

                int same = 0, del = 0;

                for (int m = i; m <= s.length(); m++) {
                    if (s[m - 1] == s[i - 1])
                        same++;
                    else
                        del++;

                    if (j + del <= k)
                        dp[m][j + del] = min(dp[m][j + del], len(same) + 1 + dp[i - 1][j]);
                    else
                        break;
                }
            }
        }

        return dp[s.length()][k];
    }

private:
    int len(int k) {   // ����k����ͬ�ַ�ת��Ϊ�г̳��ȱ����ĳ���
        if (k <= 1)
            return 0;
        else if (k > 1 && k < 10)
            return 1;
        else if (k >= 10 && k < 100)
            return 2;
        else
            return 3;
    }
};
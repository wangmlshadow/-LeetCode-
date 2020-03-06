#include "normal.h"

/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������

���ܹ��ж�������ͬ��·����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-paths
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {    // ��ʱ
public:
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        int cnt = 0;
        getCnt(1, 1, cnt);

        return cnt;
    }

private:
    int M;    // ��
    int N;    // ��

    void getCnt(int m, int n, int& cnt) {
        if (m == M && n == N) {
            cnt++;
            return;
        }
        else if (m > M || n > N)
            return;
        else {
            getCnt(m + 1, n, cnt);
            getCnt(m, n + 1, cnt);
        }
    }
};

class Solution {   // ��̬�滮
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 1));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};
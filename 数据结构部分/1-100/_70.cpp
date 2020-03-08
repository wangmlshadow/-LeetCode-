#include "normal.h"

/*

������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������
*/

class Solution {      // �ݹ鳬ʱ��
public:
    int climbStairs(int n) {
        N = n;
        cnt = 0;

        solution(1);
        solution(2);

        return cnt;
    }

private:
    int N;
    int cnt;

    void solution(int nowCnt) {
        if (nowCnt == N) {
            cnt++;
            return;
        }
        else if (nowCnt > N) {
            return;
        }
        else {
            solution(nowCnt + 1);
            solution(nowCnt + 2);
        }
    }
};

class Solution {     // ��̬�滮
public:
    int climbStairs(int n) {
        vector<long> dp(n + 1, 0);

        if (n == 1)
            return 1;

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
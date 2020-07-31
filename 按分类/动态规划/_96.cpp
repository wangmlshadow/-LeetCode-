#include "normal.h"

/*
��̬�滮

����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�
*/

class Solution {   // ��ʱ�ˣ��ݹ�
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;

        return solution(1, n);
    }

private:
    int solution(int start, int end) {
        int cnt = 0;
        if (start >= end)
            return 1;

        for (int i = start; i <= end; i++) {
            int left = solution(start, i - 1);
            int right = solution(i + 1, end);

            cnt += left * right;
        }

        return cnt;
    }
};


class Solution {    // ��̬�滮
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;

        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                res[i] += res[j - 1] * res[i - j];     // ��� j-1���ڵ� �ұ� i-j���ڵ㣨����������7-10��1-4������һ���ģ�
            }
        }

        return res[n];
    } 
};

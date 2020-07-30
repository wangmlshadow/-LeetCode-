#include "normal.h"

/*
����

����һ���������� A���ҵ� min(B) ���ܺͣ����� B �ķ�ΧΪ A ��ÿ���������������顣

���ڴ𰸿��ܴܺ���˷��ش�ģ 10^9 + 7��

˼·��1.������⣬��ʱ
*/

class Solution {  // ��91������������ʱ
public:
    int sumSubarrayMins(vector<int>& A) {
        long long res = 0;

        for (int i = 0; i < A.size(); i++) {
            int minV = INT_MAX;
            for (int j = i; j < A.size(); j++) {
                minV = min(minV, A[j]);
                res += minV;
            }
        }

        return res % 1000000007;
    }
};

class Solution {    // ���
public:
    int sumSubarrayMins(vector<int>& A) {
        const long M = 1e9 + 7;
        long long res = 0;
        stack<int> s;
        vector<long> sums(A.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            while (!s.empty() && A[s.top()] >= A[i])
                s.pop();

            if (s.empty())
                sums[i] = A[i] * (i + 1);
            else
                sums[i] = sums[s.top()] + A[i] * (i - s.top());

            sums[i] %= M;
            s.push(i);
        }

        for (int i = 0; i < A.size(); i++) {
            res += sums[i];
            res %= M;
        }

        return res;
    }
};
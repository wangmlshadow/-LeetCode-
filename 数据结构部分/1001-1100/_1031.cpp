#include "normal.h"

/*
����

�����Ǹ��������� A �������������ص�����������������Ԫ�ص����ͣ�������ĳ��ȷֱ�Ϊ L �� M��
��������Ҫ������ǣ���Ϊ L ����������Գ����ڳ�Ϊ M ��������֮ǰ��֮�󡣣�

����ʽ�Ͽ����������� V���� V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) ��������������֮һ��

0 <= i < i + L - 1 < j < j + M - 1 < A.length, ��
0 <= j < j + M - 1 < i < i + L - 1 < A.length.

˼·�������п��������������ʹ������洢�������������������е�λ�ÿ��Ա�ʾ��������A�е�λ�ã�Ȼ��������п���

*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sumL;  // �ֱ�Ϊ����ΪL��M������������������Ԫ��֮�ͣ�sumL��sumM�е�i��Ԫ�ر�ʾ��ʼλ��Ϊi����������L��M���������
        vector<int> sumM;
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < A.size(); i++) {
            if (i < L - 1)
                sum1 += A[i];
            else if (i == L - 1) {
                sum1 += A[i];
                sumL.push_back(sum1);
            }
            else {
                sum1 += A[i] - A[i - L];
                sumL.push_back(sum1);
            }
            
            if (i < M - 1)
                sum2 += A[i];
            else if (i == M - 1) {
                sum2 += A[i];
                sumM.push_back(sum2);
            }
            else {
                sum2 += A[i] - A[i - M];
                sumM.push_back(sum2);
            }
        }

        int res = INT_MIN;

        for (int i = 0; i < sumL.size(); i++) {
            for (int j = 0; j < sumM.size(); j++) {  // �ж��Ƿ��ص�
                if (i >= j + M || j >= i + L) {
                    res = max(res, sumL[i] + sumM[j]);
                }
            }
        }

        return res;
    }
};


/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��32 ms, ������ C++ �ύ�л�����13.39%���û�
�ڴ����ģ�8.8 MB, ������ C++ �ύ�л�����100.00%���û�
*/
#include "normal.h"

/*
���� 

����һ��Ԫ�ض���������������A �������� L �Լ� R (L <= R)��

���������ǿ����������Ԫ��������ڵ���L С�ڵ���R�������������

˼·��1.�����ж���i��ͷ���������Ƿ���������
      2.��������   û�п��ǵ�������� ����

*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int left = 0, right = -1, res = 0, maxVal = INT_MIN;

        for (int i = 0; i < A.size(); i++) {
            bool sign = false;  // �ж�������i-j�Ƿ���������

            for (int j = i; j < A.size(); j++) {
                if (A[j] > R)
                    break;
                
                sign = sign || A[j] >= L;

                if (sign)
                    res++;
            }
        }

        return res;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��112 ms, ������ C++ �ύ�л�����21.22%���û�
�ڴ����ģ�30.6 MB, ������ C++ �ύ�л�����50.00%���û�
*/


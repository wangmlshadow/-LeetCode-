#include "normal.h"

/*
����

�������� k �����㷵�غ�Ϊ k ��쳲��������ֵ�������Ŀ�����У�ÿ��쳲��������ֶ����Ա�ʹ�ö�Ρ�

쳲��������ֶ���Ϊ��

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 �� ���� n > 2 ��
���ݱ�֤���ڸ����� k ��һ�����ҵ����н⡣

˼·��ʹ�����鰴˳�򱣴�����С��k��쳲��������� ÿ�ν�k��ȥһ����ӽ�����쳲�������ֵ ֱ��k==0
*/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {       
        if (k < 3)
            return 1;

        vector<int> fb(2, 1);
        int a = 1, b = 1;

        while (a + b <= k) {
            fb.push_back(a + b);
            a = b;
            b = *fb.rbegin();
        }

        int res = 0, index = fb.size() - 1;

        while (k != 0) {
            if (fb[index] <= k) {
                res++;
                k -= fb[index];
            }
            else
                index--;
        }

        return res;
    }
};

/*
ִ�н����ͨ�� ��ʾ����
ִ����ʱ��4 ms, ������ C++ �ύ�л�����76.85%���û�
�ڴ����ģ�6.6 MB, ������ C++ �ύ�л�����100.00%���û�
*/
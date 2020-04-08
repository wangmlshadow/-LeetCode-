#include "normal.h"

/*
����һ������ n������ n! ���β�������������
*/

class Solution {
public:
    int trailingZeroes(int n) {
        long num = 1;   // �������������������Χ

        while (n > 0)
            num = num * n--;

        string str = to_string(num);
        int len = str.length(), cnt = 0;

        for (int i = len - 1; i >= 0; i--) {
            if (str[i] == '0')
                cnt++;
            else
                break;
        }            

        return cnt;
    }
};



class Solution {  // �����β����0������ �۲�׳˼���ʱ��û��10 100��
public:
    int trailingZeroes(int n) {
        // 10 5 2
        vector<int> helper(3, 0);  // ��¼10 5 2 �ĸ���
        int cnt = 0;   // ��¼β����0������ ��ʵ���ǽ׳��п��Բ��������10

        for (int i = 2; i <= n; i++) {   // ���ǳ�ʱ��
            int val = i;

            if (val >= 10) {
                while (val % 10 == 0) {
                    helper[0]++;
                    val = val / 10;
                }
            }

            if (val >= 5) {
                while (val % 5 == 0) {
                    helper[1]++;
                    val = val / 5;
                }
            }

            if (val >= 2) {
                while (val % 2 == 0) {
                    helper[2]++;
                    val = val / 2;
                }
            }
        }

        cnt = helper[0] + min(helper[1], helper[2]);

        return cnt;
    }
};


class Solution {
public:
    int trailingZeroes(int n) {   // 2���ֵı�5�� ֻ��Ҫ����5�ĸ���
        int cnt = 0;

        while (n >= 5) {
            n = n / 5;
            cnt += n;            
        }

        return cnt;
    }
};
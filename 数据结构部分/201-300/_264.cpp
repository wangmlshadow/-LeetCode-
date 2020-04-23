#include "normal.h"

/*
��дһ�������ҳ��� n ��������

��������ֻ���������� 2, 3, 5 ����������

˵��:

1 �ǳ�����
n ������1690��
*/

class Solution {   // ��ʱ
public:
    int nthUglyNumber(int n) {
        int res = 1;

        while (n != 0) {
            if (isUgly(res))
                n--;

            res++;
        }

        return res - 1;
    }

    bool isUgly(int num) {
        if (num <= 0)
            return false;

        int ex = num;

        while (ex % 2 == 0)
            ex /= 2;

        while (ex % 3 == 0)
            ex /= 3;

        while (ex % 5 == 0)
            ex /= 5;

        return ex == 1;
    }
};


class Solution {   // ��̬�滮
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int two = 0, three = 0, five = 0;

        for (int i = 1; i < n; i++) {
            int cur = min(res[two] * 2, min(res[three] * 3, res[five] * 5));
            res.push_back(cur);

            if (cur == res[two] * 2)
                two++;
            
            if (cur == res[three] * 3)
                three++;

            if (cur == res[five] * 5)
                five++;
        }

        return *res.rbegin();
    }
};
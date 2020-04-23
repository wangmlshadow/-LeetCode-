#include "normal.h"

/*
��дһ�������жϸ��������Ƿ�Ϊ������

��������ֻ���������� 2, 3, 5 ����������
*/


class Solution {
public:
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
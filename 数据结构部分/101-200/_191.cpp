#include "normal.h"

/*
��дһ��������������һ���޷�������������������Ʊ��ʽ������λ��Ϊ ��1�� �ĸ�����Ҳ����Ϊ������������
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while (n != 0) {
            if (n % 2 == 1)
                cnt++;

            n = n / 2;
        }

        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while (n != 0) {
            if (n % 2 == 1)
                cnt++;

            n >>= 1;
        }

        return cnt;
    }
};
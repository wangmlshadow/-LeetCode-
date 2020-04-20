#include "normal.h"

/*
����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n > 2) {
            if (n % 2 != 0)
                return false;

            n >>= 1;
        }

        return true;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n > 2) {
            if (n & 1 != 0)
                return false;

            n >>= 1;
        }

        return true;
    }
};
#include "normal.h"

/*
������Χ [m, n]������ 0 <= m <= n <= 2147483647�����ش˷�Χ���������ֵİ�λ�루���� m, n ���˵㣩��
*/

class Solution {   // �϶���ʱ��
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;

        for (int i = m + 1; i <= n; i++)
            res &= i;

        return res;
    }
};

class Solution { // ͨ�����в������� ���Ǳ�����ʱ
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n)
            return m;

        int sub = n - m;

        if (sub >= m)
            return 0;

        int res = m;

        for (int i = m + 1; i <= n; i++) {
            res &= i;

            if (res == 0 || i == INT_MAX)
                break;
        }
        return res;
    }
};

class Solution {  // �����ٶ�>73%
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n)
            return m;

        int cnt = 0; // ������ұ�0�ĸ���

        while (n > m) {
            cnt++;
            n >>= 1;
            m >>= 1;
        }

        return m << cnt;
    }
};

class Solution {  // �����ٶ�>13%
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n &= (n - 1);
        }

        return n;
    }
};

class Solution {  // �����ٶ�>49%
public:
    int rangeBitwiseAnd(int m, int n) {
        if (n - m >= m)
            return 0;

        while (n > m) {
            n &= (n - 1);
        }

        return n;
    }
};
#include "normal.h"

/*
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        stringstream ss;
        ss << x;
        string str = ss.str();
        int len = str.length();

        for (int i = 0; i <= len / 2; i++) {
            if (str[i] != str[len - i - 1])
                return false;
        }

        return true;
    }
};
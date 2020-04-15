#include "normal.h"

/*
����һ���ַ��� s�������ͨ�����ַ���ǰ������ַ�����ת��Ϊ���Ĵ����ҵ������ؿ��������ַ�ʽת������̻��Ĵ���
*/

class Solution {   // ��ʱ��
public:
    string shortestPalindrome(string s) {
        int len = s.length();

        if (len < 2)
            return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        for (int i = 0; i < len; i++) {
            if (s.substr(0, len - i) == rev.substr(i)) {
                rev += s.substr(len - i, i);
                break;
            }
        }

        return rev;
    }
};


class Solution {   // �ݹ�
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        int i = 0;

        for (int j = len - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }

        if (i == len)
            return s;

        string rev = s.substr(i);
        reverse(rev.begin(), rev.end());

        return rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
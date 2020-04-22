#include "normal.h"

/*
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����
*/

class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);

        while (s.length() != 1) {
            int cur = 0;

            for (auto c : s) {
                cur = cur + c - '0';
            }

            s = to_string(cur);
        }

        return stoi(s);
    }
};

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
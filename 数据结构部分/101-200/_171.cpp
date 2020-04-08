#include "normal.h"

/*
����һ��Excel����е������ƣ���������Ӧ������š�
*/

class Solution {
public:
    int titleToNumber(string s) {
        long res = 0;
        int len = s.length();
        long cnt = 1;

        for (int i = len - 1; i >= 0; i--) {
            int cur = s[i] - 'A' + 1;
            res = res + cur * cnt;
            cnt = cnt * 26;
        }

        return res;
    }
};

/*
ִ�н����ͨ��
��ʾ����
ִ����ʱ :0 ms, ������ C++ �ύ�л�����100.00%���û�
�ڴ����� :5.9 MB, ������ C++ �ύ�л�����100.00%���û�
*/
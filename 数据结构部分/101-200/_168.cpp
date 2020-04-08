#include "normal.h"

/*
����һ������������������ Excel �������Ӧ�������ơ�
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;

        // ��26ȡ��
        while (n > 26) {
            int i = (n - 1) % 26;
            res.push_back('A' + i);
            n = (n - 1) / 26;
        }
        
        if (n != 0)
            res.push_back('A' + n - 1);

        reverse(res.begin(), res.end());

        return res;
    }
};

/*
ִ�н����ͨ��
��ʾ����
ִ����ʱ :0 ms, ������ C++ �ύ�л�����100.00%���û�
�ڴ����� :5.9 MB, ������ C++ �ύ�л�����100.00%���û�
*/
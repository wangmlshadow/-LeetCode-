#include "normal.h"

/*
����һ��ֻ���� '(' �� ')' ���ַ������ҳ���İ�����Ч���ŵ��Ӵ��ĳ��ȡ�
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mySt;
        int len = 0;
        mySt.push(-1);  // ע��˴�

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                mySt.push(i);
            else {
                mySt.pop();

                if (mySt.empty())
                    mySt.push(i);     // ��֤�����ڿ�ջ�� ջ��Ҫôʱ-1��Ҫô�ǵ�һ����Чλ��
                else {
                    len = (len > i - mySt.top()) ? len : i - mySt.top();
                }
            }
        }

        return len;
    }
};
#include "normal.h"

/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        string str = strs[0];
        int i, j;

        for (i = 1; i < strs.size(); i++) {
            for (j = 0; j < min(str.length(), strs[i].length()); j++) {
                if (str[j] != strs[i][j])
                    break;
            }

            if (j == 0)
                return "";

            if (j < str.length())
                str = str.substr(0, j);
        }

        return str;
     }
};
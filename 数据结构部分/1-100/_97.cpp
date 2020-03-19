#include "normal.h"

/*
���������ַ��� s1, s2, s3, ��֤ s3 �Ƿ����� s1 �� s2 ������ɵġ�
*/

class Solution {    // ��ά��̬�滮
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len_1 = s1.length();
        int len_2 = s2.length();

        if (len_1 + len_2 != s3.length())
            return false;

        vector<vector<bool>> res(len_1 + 1, vector<bool>(len_2 + 1, false));

        for (int i = 0; i <= len_1; i++) {    //  s1��ǰi���ַ���s2��ǰj���ַ��Ƿ���Խ������s3��ǰi+j���ַ�
            for (int j = 0; j <= len_2; j++) {
                if (i == 0 && j == 0)
                    res[i][j] = true;
                else if (i == 0)
                    res[i][j] = res[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    res[i][j] = res[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                else
                    res[i][j] = (res[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (res[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return res[len_1][len_2];
    }
};
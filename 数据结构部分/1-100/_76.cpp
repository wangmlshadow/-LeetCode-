#include "normal.h"

/*
����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T ������ĸ����С�Ӵ���
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int len_1 = s.length();
        int len_2 = t.length();
        map<char, int> pos;

        for (int i = 0; i < len_2; i++)
            ++pos[t[i]];
        
        int left = 0, max = len_1 + 1, cnt = 0, start = left;

        for (int i = 0; i < len_1; i++) {
            if (--pos[s[i]] >= 0)
                cnt++;

            while (cnt == len_2) {
                if (max > i - left + 1) {
                    max = i - left + 1;
                    start = left;
                }

                if (++pos[s[left]] > 0)
                    cnt--;

                left++;
            }
        }

        return (max == len_1 + 1) ? "" : s.substr(start, max);
    }
};